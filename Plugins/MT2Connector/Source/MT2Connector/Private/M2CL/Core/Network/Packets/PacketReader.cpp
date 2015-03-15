#include "MT2ConnectorPrivatePCH.h"
#include "PacketReader.h"

#include "Packets.h"
#include "../../Logger.h"

#include <iostream>



PacketReader::PacketReader() {

}

PacketReader::~PacketReader() {

}

int32 PacketReader::getEstimatedPacketSize(uint8 header) {
    switch (header) {
        case GC_PING:
            return (int32)sizeof(GCPing);
        case GC_PHASE:
            return (int32)sizeof(GCPhase);
        case GC_HANDSHAKE:
            return (int32)sizeof(GCHandshake);
        case GC_KEYAGREEMENT:
            return (int32)sizeof(GCKeyAgreement);
        case GC_KEYAGREEMENT_COMPLETED:
            return (int32)sizeof(GCKeyAgreementCompleted);
        case GC_LOGIN_FAILURE:
            return (int32)sizeof(GCLoginFailure);
        case GC_AUTH_SUCCESS:
            return (int32)sizeof(GCAuthSuccess);
        case GC_HYBRID_CRYPT_KEYS:
            return -((int32)sizeof(GCHybridCryptKeys));  // dynamic packet size
        case GC_EMPIRE:
            return (int32)sizeof(GCEmpire);
        case GC_LOGIN_SUCCESS:
            return (int32)sizeof(GCLoginSuccess);
        case GC_POINT_CHANGE:
            return (int32)sizeof(GCPointChange);
        case GC_CHARACTER_BGM_VOL:
            return (int32)sizeof(GCCharacterBGMVol);
        case GC_CHAT:
            return -((int32)sizeof(GCChat));  // dynamic packet size
        case GC_QUICKSLOT_ADD:
            return (int32)sizeof(GCQuickslotAdd);
        case GC_POINTS:
            return (int32)sizeof(GCPoints);
        case GC_SKILL_LEVEL:
            return (int32)sizeof(GCSkillLevel);
        case GC_ITEM_SET:
            return (int32)sizeof(GCItemSet);
        case GC_ITEM_UPDATE:
            return (int32)sizeof(GCItemUpdate);
        case GC_CHARACTER_ADD:
            return (int32)sizeof(GCCharacterAdd);
        case GC_CHARACTER_ADDITIONAL_INFO:
            return (int32)sizeof(GCCharacterAdditionalInfo);
        case GC_NPC_POSITION:
            return -((int32)sizeof(GCNPCPosition));  // dynamic packet size
        case GC_CHARACTER_UPDATE:
            return (int32)sizeof(GCCharacterUpdate);
        case GC_AFFECT_ADD:
            return (int32)sizeof(GCAffectAdd);
        case GC_MOVE:
            return (int32)sizeof(GCMove);
        case GC_GUILD:
            return -((int32)sizeof(GCGuild));  // dynamic packet size
        case GC_WALK_MODE:
            return (int32)sizeof(GCWalkMode);
        case GC_LAND_LIST:
            return -((int32)sizeof(GCLandList));
        case GC_TIME:
            return (int32)sizeof(GCTime);
        case GC_CHANNEL:
            return (int32)sizeof(GCChannel);
        case GC_AFFECT_REMOVE:
            return (int32)sizeof(GCAffectRemove);
        case GC_WHISPER:
            return -((int32)sizeof(GCWhisper));
        case GC_OWNERSHIP:
            return (int32)sizeof(GCOwnership);
        case GC_STUN:
            return (int32)sizeof(GCStun);
        case GC_CREATE_FLY:
            return (int32)sizeof(GCCreateFly);
        case GC_DEAD:
            return (int32)sizeof(GCDead);
        case GC_CHARACTER_DELETE:
            return (int32)sizeof(GCCharacterDelete);
        case GC_ITEM_GROUND_ADD:
            return (int32)sizeof(GCItemGroundAdd);
        case GC_ITEM_GROUND_DEL:
            return (int32)sizeof(GCItemGroundDel);
        case GC_PVP:
            return (int32)sizeof(GCPVP);
        case GC_SCRIPT:
            return -((int32)sizeof(GCScript));
        case GC_QUEST_INFO:
            return -((int32)sizeof(GCQuestInfo));
        case GC_WARP:
            return (int32)sizeof(GCWarp);
        case GC_ITEM_OWNERSHIP:
            return (int32)sizeof(GCItemOwnership);
        case GC_FISHING:
            return (int32)sizeof(GCFishing);
        case GC_FLY_TARGETING:
            return (int32)sizeof(GCFlyTargeting);
        case GC_CHARACTER_CREATE_SUCCESS:
            return sizeof(GCCharacterCreateSuccess);
        case GC_EXCHANGE:
            return (int32)sizeof(GCExchange);
        default:
            return 0;
    }
}

void *PacketReader::getPacket(uint8 header, std::vector<uint8> data) {
    // Check packet size
    int32 size = getEstimatedPacketSize(header);
    if(data.size() != size && size > -1) {
        Logger::getInstance()->fatal("Failed to read packet due to size missmatch");
        return nullptr;
    }

    // Convert uint8 vector to uint8 array
    uint8* byteData = new uint8[data.size()];
    for(uint32 x = 0; x < data.size(); x++) {
        byteData[x] = data.at(x);
    }

    // Switch to the right packet and return it
    switch(header) {
        case GC_PING:
            return (GCPing*)byteData;
        case GC_PHASE:
            return (GCPhase *) byteData;
        case GC_HANDSHAKE:
            return (GCHandshake *) byteData;
        case GC_KEYAGREEMENT:
            return (GCKeyAgreement *) byteData;
        case GC_KEYAGREEMENT_COMPLETED:
            return (GCKeyAgreementCompleted*) byteData;
        case GC_LOGIN_FAILURE:
            return (GCLoginFailure*) byteData;
        case GC_AUTH_SUCCESS:
            return (GCAuthSuccess*) byteData;
        case GC_HYBRID_CRYPT_KEYS:
            return (GCHybridCryptKeys*) byteData;
        case GC_EMPIRE:
            return (GCEmpire*) byteData;
        case GC_LOGIN_SUCCESS:
            return (GCLoginSuccess*) byteData;
        case GC_POINT_CHANGE:
            return (GCPointChange*) byteData;
        case GC_CHARACTER_BGM_VOL:
            return (GCCharacterBGMVol*) byteData;
        case GC_CHAT:
            return (GCChat*) byteData;
        case GC_QUICKSLOT_ADD:
            return (GCQuickslotAdd*) byteData;
        case GC_POINTS:
            return (GCPoints*) byteData;
        case GC_SKILL_LEVEL:
            return (GCSkillLevel*) byteData;
        case GC_ITEM_SET:
            return (GCItemSet*) byteData;
        case GC_ITEM_UPDATE:
            return (GCItemUpdate*) byteData;
        case GC_CHARACTER_ADD:
            return (GCCharacterAdd*) byteData;
        case GC_CHARACTER_ADDITIONAL_INFO:
            return (GCCharacterAdditionalInfo*) byteData;
        case GC_NPC_POSITION:
            return (GCNPCPosition*) byteData;
        case GC_CHARACTER_UPDATE:
            return (GCCharacterUpdate*) byteData;
        case GC_AFFECT_ADD:
            return (GCAffectAdd*) byteData;
        case GC_MOVE:
            return (GCMove*) byteData;
        case GC_GUILD:
            return (GCGuild*) byteData;
        case GC_WALK_MODE:
            return (GCWalkMode*) byteData;
        case GC_LAND_LIST:
            return (GCLandList*) byteData;
        case GC_TIME:
            return (GCTime*) byteData;
        case GC_CHANNEL:
            return (GCChannel*) byteData;
        case GC_AFFECT_REMOVE:
            return (GCAffectRemove*) byteData;
        case GC_WHISPER:
            return (GCWhisper*) byteData;
        case GC_OWNERSHIP:
            return (GCOwnership*) byteData;
        case GC_STUN:
            return (GCStun*) byteData;
        case GC_CREATE_FLY:
            return (GCCreateFly*) byteData;
        case GC_DEAD:
            return (GCDead*) byteData;
        case GC_CHARACTER_DELETE:
            return (GCCharacterDelete*) byteData;
        case GC_ITEM_GROUND_ADD:
            return (GCItemGroundAdd*) byteData;
        case GC_ITEM_GROUND_DEL:
            return (GCItemGroundDel*) byteData;
        case GC_PVP:
            return (GCPVP*) byteData;
        case GC_SCRIPT:
            return (GCScript*) byteData;
        case GC_QUEST_INFO:
            return (GCQuestInfo*) byteData;
        case GC_WARP:
            return (GCWarp*) byteData;
        case GC_ITEM_OWNERSHIP:
            return (GCItemOwnership*) byteData;
        case GC_FISHING:
            return (GCFishing*) byteData;
        case GC_FLY_TARGETING:
            return (GCFlyTargeting*) byteData;
        case GC_CHARACTER_CREATE_SUCCESS:
            return (GCCharacterCreateSuccess*) byteData;
        case GC_EXCHANGE:
            return (GCExchange*) byteData;
        default:
           Logger::getInstance()->fatal("Packet %i isn't implemented in getPacket", header);
            return nullptr;
    }
}
