#pragma once

#include <string>
#include "AllowWindowsPlatformTypes.h"
#include <boost/asio.hpp>
#include "HideWindowsPlatformTypes.h"
#include <cipher.h>
#include "MT2ClientThread.h"

#include "Packets/PacketReader.h"

class FMT2ClientThread;
class TcpClient {
public:
	TcpClient(FMT2ClientThread* listener, std::string authIp, uint16 authPort, std::string channelIp, uint16 channelPort);
	~TcpClient();

	void connect(std::string ip, uint16 port);
	bool read();
	bool send(void* data, uint32 length);

	static TcpClient* getInstance();

private:
	FMT2ClientThread* listener;
	std::string currentIp;
	uint16 currentPort;

	std::string channelIp;
	uint16 channelPort;
	PacketReader packetReader;

	boost::asio::io_service ioService;
	boost::asio::ip::tcp::resolver resolver;
	boost::asio::ip::tcp::socket socket;

	Cipher cipher;
	uint32 sequenceLocation;

	static TcpClient* instance;



};
