#include "MT2ConnectorPrivatePCH.h"
#include <cryptopp/config.h>
#include "Packets.h"


void Packets::init() {
    if(isInit)
        return;

    gcPacketNames = std::map<uint8, std::string> {
            {GC_AUTH_SUCCESS,               "GCAuthSuccess"},
            {GC_HANDSHAKE,                  "GCHandshake"},
            {GC_KEYAGREEMENT,               "GCKeyAgreement"},
            {GC_KEYAGREEMENT_COMPLETED,     "GCKeyAgreementCompleted"},
            {GC_LOGIN_FAILURE,              "GCLoginFailure"},
            {GC_PHASE,                      "GCPhase"},
            {GC_PING,                       "GCPing"},
            {GC_HYBRID_CRYPT_KEYS,          "GCHybridCryptKeys"},
            {GC_EMPIRE,                     "GCEmpire"},
            {GC_LOGIN_SUCCESS,              "GCLoginSuccess"},
            {GC_POINT_CHANGE,               "GCPointChange"},
            {GC_CHARACTER_BGM_VOL,          "GCCharacterBGMVol"},
            {GC_CHAT,                       "GCChat"},
            {GC_QUICKSLOT_ADD,              "GCQuickslotAdd"},
            {GC_POINTS,                     "GCPoints"},
            {GC_SKILL_LEVEL,                "GCSkillLevel"},
            {GC_ITEM_SET,                   "GCItemSet"},
            {GC_ITEM_UPDATE,                "GCItemUpdate"},
            {GC_CHARACTER_ADD,              "GCCharacterAdd"},
            {GC_CHARACTER_ADDITIONAL_INFO,  "GCCharacterAdditionalInfo"},
            {GC_NPC_POSITION,               "GCNPCPosition"},
            {GC_CHARACTER_UPDATE,           "GCCharacterUpdate"},
            {GC_AFFECT_ADD,                 "GCAffectAdd"},
            {GC_MOVE,                       "GCMove"},
            {GC_GUILD,                      "GCGuild"},
            {GC_WALK_MODE,                  "GCWalkMode"},
            {GC_LAND_LIST,                  "GCLandList"},
            {GC_TIME,                       "GCTime"},
            {GC_CHANNEL,                    "GCChannel"},
            {GC_AFFECT_REMOVE,              "GCAffectRemove"},
            {GC_WHISPER,                    "GCWhisper"},
            {GC_OWNERSHIP,                  "GCOwnership"},
            {GC_STUN,                       "GCStun"},
            {GC_CREATE_FLY,                 "GCCreateFly"},
            {GC_DEAD,                       "GCDead"},
            {GC_CHARACTER_DELETE,           "GCCharacterDelete"},
            {GC_ITEM_GROUND_ADD,            "GCItemGroundAdd"},
            {GC_ITEM_GROUND_DEL,            "GCItemGroundDel"},
            {GC_PVP,                        "GCPVP"},
            {GC_SCRIPT,                     "GCScript"},
            {GC_QUEST_INFO,                 "GCQuestInfo"},
            {GC_WARP,                       "GCWarp"},
            {GC_ITEM_OWNERSHIP,             "GCItemOwnership"},
            {GC_FISHING,                    "GCFishing"},
            {GC_FLY_TARGETING,              "GCFlyTargeting"},
            {GC_CHARACTER_CREATE_SUCCESS,   "GCCharacterCreateSuccess"},
            {GC_EXCHANGE,                   "GCExchange"},
    };

    cgPacketNames = std::map<uint8, std::string> {
            {CG_LOGIN2,                     "CGLogin2"},
            {CG_LOGIN3,                     "CGLogin3"},
            {CG_PONG,                       "CGPong"},
            {GC_HANDSHAKE,                  "CGHandshake"},
            {GC_KEYAGREEMENT,               "CGKeyAgreement"},
            {CG_CHARACTER_SELECT,           "CGCharacterSelect"},
            {CG_ENTERGAME,                  "CGEnterGame"},
            {CG_CLIENT_VERSION,             "CGClientVersion"},
            {CG_CLIENT_VERSION2,            "CGClientVersion2"},
            {CG_CHARACTER_CREATE,           "CGCharacterCreate"},
            {CG_ITEM_PICKUP,                "CGItemPickup"},
            {CG_EXCHANGE,                   "CGExchange"},
            {CG_MOVE,                       "CGMove"},
    };

    cgHasSequences = std::map<uint8, bool> {
            {CG_LOGIN3,                     true},
            {CG_PONG,                       true},
            {CG_LOGIN2,                     true},
            {CG_CHARACTER_SELECT,           true},
            {CG_ENTERGAME,                  true},
            {CG_CLIENT_VERSION,             true},
            {CG_CLIENT_VERSION2,            true},
            {CG_CHARACTER_CREATE,           true},
            {CG_EMPIRE,                     true},
            {CG_ITEM_PICKUP,                true},
            {CG_EXCHANGE,                   true},
            {CG_MOVE,                       true},
    };
}

std::string Packets::getGCPacketName(uint8 header) {
    if(!isInit)
        init();

    if(gcPacketNames.count(header) == 1)
        return gcPacketNames[header];

    return "UNKNOWN";
}

std::string Packets::getCGPacketName(uint8 header) {
    if(!isInit)
        init();

    if(cgPacketNames.count(header) == 1)
        return cgPacketNames[header];

    return "UNKNOWN";
}

bool Packets::hasCGPacketSequence(uint8 header) {
    return cgHasSequences.count(header) == 1 ? cgHasSequences[header] : false;
}


std::map<uint8, std::string> Packets::gcPacketNames = std::map<uint8, std::string>();
std::map<uint8, std::string> Packets::cgPacketNames = std::map<uint8, std::string>();
std::map<uint8, bool> Packets::cgHasSequences = std::map<uint8, bool>();

bool Packets::isInit = false;
