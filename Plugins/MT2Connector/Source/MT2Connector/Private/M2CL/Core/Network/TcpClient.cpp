#include "MT2ConnectorPrivatePCH.h"
#include "TcpClient.h"

#include <boost/array.hpp>
#include <iostream>

#include "../Logger.h"
#include "Packets/Packets.h"

#include "../PythonAPI/ListenerModule.h"
#include "../Timer.h"

#include <sequence.h>
#include <vector>



TcpClient::TcpClient(FMT2ClientThread* listener , std::string authIp, uint16 authPort, std::string channelIp, uint16 channelPort) :
    resolver(ioService),
    socket(ioService),
    packetReader(),
    cipher()
{
    connect(authIp, authPort);
	this->listener = listener;
    instance = this;
    sequenceLocation = 0;

    this->channelIp = channelIp;
    this->channelPort = channelPort;
}

TcpClient::~TcpClient() {

}

void TcpClient::connect(std::string ip, uint16 port) {
    if(currentIp.compare(ip) == 0 && currentPort == port) {
        return; // We are already connected on this ip:port so we can ignore it
    }

    if(socket.is_open()) {
        if(cipher.activated())
            cipher.set_activated(false);
        sequenceLocation = 0;
        socket.close();
    }

    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::from_string(ip), port);

    Logger::getInstance()->info("Connect to %s on port %i", ip.c_str(), port);
    boost::system::error_code error;
    socket.connect(endpoint, error);
    if(error) {
        Logger::getInstance()->fatal("Error while connecting to server (%s)", error.message().c_str());
    } else {
        Logger::getInstance()->info("Connected to server");
    }

    currentIp = ip;
    currentPort = port;
}

bool TcpClient::read() {
    boost::system::error_code error;
    boost::array<uint8, 50000> buf;

    uint32 len = socket.read_some(boost::asio::buffer(buf), error);
    if(error == boost::asio::error::eof) {
        Logger::getInstance()->fatal("Socket is eof");
        return false; // exit
    }

    uint8* workingBuffer = new uint8[len];
    for(uint32 i = 0; i < len; i++) {
        workingBuffer[i] = buf.at(i);
    }

    if(cipher.activated()) {
        cipher.Decrypt((char*)workingBuffer, len);
    }

    int32 packetSize = 0;
    uint8 currentHeader = 0;
    bool dynamic = false;
    std::vector<uint8> packetData = std::vector<uint8>();

    for(uint32 i = 0; i < len; i++) {
        uint8 data = workingBuffer[i];
        packetData.push_back(data);

        // Start new packet
        if(currentHeader == 0) {
            currentHeader = data;

            packetSize = packetReader.getEstimatedPacketSize(currentHeader);
            if(packetSize == 0) {
                // Unknown packet - packet analyse and exit
                Logger::getInstance()->fatal("Unknown packet header %i", currentHeader);
                Logger::getInstance()->fatal("Starting Packet Analayse (print uint8 buffer):");
                Logger::getInstance()->fatal("Buffer Size %i:", static_cast<int32>(len));
                for(uint32 x = i; x < len; x++) {
                    Logger::getInstance()->fatal("%i", workingBuffer[x]);
                }
                return false;
            } else {
                dynamic = packetSize < 0;
				std::string packetName = Packets::getGCPacketName(currentHeader);
				if (packetName == "UNKNOWN") {
					Logger::getInstance()->debug("Recv %i (buffer: %i, estimated: %i)", currentHeader, len - i, packetSize);
				}
				else {
					Logger::getInstance()->debug("Recv %s (buffer: %i, estimated: %i)", packetName, len - i, packetSize);
				}

                
            }
        }

        if(packetData.size() == 3 && packetSize < 0) {
            uint16 length = packetData.at(1) | (packetData.at(2) << 8);
            Logger::getInstance()->debug("Dynamic Packet Size is %i", length);
            int32 x = packetSize;
            packetSize = length;

            if(x < -packetSize) {
                Logger::getInstance()->warn("Dynamic Packet Size is less than minimum size");
            }
        }

        if(packetData.size() == packetSize && packetData.size() > 0) {
            void* packet = packetReader.getPacket(currentHeader, packetData);
            if(currentHeader == GC_HANDSHAKE) {
                GCHandshake* handshake = (GCHandshake*)packet;

                Timer::getInstance()->setServerTime(handshake->time + handshake->delta);
				uint32 handshakevalue = handshake->handshake;
				uint32 handshaketime = handshake->time;
				int32 handshakedelta = handshake->delta;
                handshake->time = handshake->time + handshake->delta + handshake->delta;
                handshake->delta = 0;

                send(handshake, sizeof(*handshake));
            }
            if(currentHeader == GC_KEYAGREEMENT) {
                GCKeyAgreement* incoming = (GCKeyAgreement*)packet;
                GCKeyAgreement outgoing;

                int32 dataLength = 265;
                size_t agreedLength = cipher.Prepare(outgoing.data, &dataLength);

                if(agreedLength == 0) {
                    Logger::getInstance()->fatal("Failed to prepare cipher");
                    return false;
                } else {
                    Logger::getInstance()->debug("Cipher prepared (%i, %i)", dataLength, (int32)agreedLength);
                }

                if(cipher.Activate(true, incoming->agreedLength, incoming->data, incoming->dataLength)) {
                    Logger::getInstance()->debug("Cipher activated (this means not enabled)");


                    outgoing.header = GC_KEYAGREEMENT;
                    outgoing.dataLength = (uint16)dataLength;
                    outgoing.agreedLength = (uint16)agreedLength;

                    send(&outgoing, sizeof(outgoing));
                } else {
                    Logger::getInstance()->fatal("Failed to activate cipher");
                    return false;
                }
            }
            if(currentHeader == GC_KEYAGREEMENT_COMPLETED) {
                Logger::getInstance()->debug("Cipher enabled");
                cipher.set_activated(true);
            }
            if(currentHeader == GC_PING) {
                // ping -> pong
                CGPong* pong = new CGPong();
                pong->header = CG_PONG;
                send(pong, sizeof(*pong));
            }
            if(currentHeader == GC_PHASE) {
                GCPhase* phase = (GCPhase*)packet;
				listener->changePhase(phase->phase);
                Logger::getInstance()->debug("Change phase to %i", phase->phase);
            }
            if(currentHeader == GC_CHAT) {
                GCChat* chat = (GCChat*)packet;
                Logger::getInstance()->info("Chat %i: %s", chat->type, chat->text);
            }
            if(currentHeader == GC_WHISPER) {
                GCWhisper* whisper = (GCWhisper*)packet;
                Logger::getInstance()->info("Whisper %s: %s", whisper->getNameFrom().c_str(), whisper->getText().c_str());
            }
            if(currentHeader == GC_WARP) {
                GCWarp* warp = (GCWarp*)packet;
                Logger::getInstance()->info("Warp to port %i (%i)", warp->port, warp->header);

                int32 block0 = warp->addr & 0xFF;
                int32 block1 = warp->addr >> 8 & 0xFF;
                int32 block2 = warp->addr >> 16 & 0xFF;
                int32 block3 = warp->addr >> 24 & 0xFF;
                printf("%lu.%lu.%lu.%lu\n", block0, block1, block2, block3);
            }
            if(currentHeader == GC_SCRIPT) {
                GCScript* script = (GCScript*)packet;
                Logger::getInstance()->info("Script: %s", script->script);
            }

            uint8 oldHeader = currentHeader;
            currentHeader = 0;
            packetData = std::vector<uint8>();

            // Call listeners
            this->listener->callListenerFunction(oldHeader, packet);
        }
    }

    if(currentHeader != 0) {
        Logger::getInstance()->warn("Unfinished packet with header %i", currentHeader);
    }

    return true;
}

bool TcpClient::send(void* data, uint32 length) {
    char* tmpPacketData = (char *) data;

    uint8 header = (uint8)tmpPacketData[0];

    if(Packets::hasCGPacketSequence(header)) { // require sequence
        tmpPacketData = new char[length+1];
        // Copy data to tmpPacketData
        for(uint32 i = 0; i < length; i++) {
            tmpPacketData[i] = ((char*)data)[i];
        }
        tmpPacketData[length] = get_sequence(sequenceLocation++);
        length += 1;
    }

    if(cipher.activated()) {
        cipher.Encrypt(tmpPacketData, length);
    }

    std::string packetName = Packets::getCGPacketName(header);
    if(packetName == "UNKNOWN") {
        Logger::getInstance()->debug("Send %i (%u)", header, length);
    } else {
        Logger::getInstance()->debug("Send %s (%u)", packetName.c_str(), length);
    }

    boost::system::error_code er;
    socket.send(boost::asio::buffer(tmpPacketData, length), 0, er);

    if(sequenceLocation == SEQUENCE_MAX_NUM) {
        sequenceLocation = 0;
    }

    return !er;
}

TcpClient* TcpClient::getInstance() {
    return instance;
}

TcpClient* TcpClient::instance = nullptr;