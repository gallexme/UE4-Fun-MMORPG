#include "MT2ConnectorPrivatePCH.h"

#include "ListenerModule.h"
#include "../Logger.h"

#include "../Network/Packets/Packets.h"


//TODO: interface
ListenerModule::ListenerModule() {


    listeners.push_back(this);

   Logger::getInstance()->debug("Register a listener");
}
void ListenerModule::AddListenerModule(ListenerModule* listener) {
	listeners.push_back(listener);
}

ListenerModule::~ListenerModule() {

}

void ListenerModule::callListenerFunction(uint8 header, void* packet) {
    try {
        // Add packets here for python listening
        switch(header) {
		case GC_HANDSHAKE:
			//boost::python::call_method<void>(self, "onPacket", header, (Packets::GCHandshake*) packet);
                break;
            case GC_KEYAGREEMENT:
				//boost::python::call_method<void>(self, "onPacket", header, (Packets::GCKeyAgreement*) packet);
                break;
            case GC_KEYAGREEMENT_COMPLETED:
				//boost::python::call_method<void>(self, "onPacket", header, (Packets::GCKeyAgreementCompleted*) packet);
                break;
            case GC_PHASE:
				//boost::python::call_method<void>(self, "onPacket", header, (Packets::GCPhase*) packet);
                break;
            case GC_PING:
				//boost::python::call_method<void>(self, "onPacket", header, (Packets::GCPing*) packet);
                break;
            case GC_LOGIN_FAILURE:
				//boost::python::call_method<void>(self, "onPacket", header, (Packets::GCLoginFailure*) packet);
                break;
            case GC_AUTH_SUCCESS:
				//boost::python::call_method<void>(self, "onPacket", header, (Packets::GCAuthSuccess*) packet);
                break;
            case GC_HYBRID_CRYPT_KEYS:
				//boost::python::call_method<void>(self, "onPacket", header, (Packets::GCHybridCryptKeys*) packet);
                break;
            case GC_EMPIRE:
				//boost::python::call_method<void>(self, "onPacket", header, (Packets::GCEmpire*) packet);
                break;
            case GC_LOGIN_SUCCESS:
				//boost::python::call_method<void>(self, "onPacket", header, (Packets::GCLoginSuccess*) packet);
                break;
            case GC_POINT_CHANGE:
				//boost::python::call_method<void>(self, "onPacket", header, (Packets::GCPointChange*) packet);
                break;
            case GC_CHARACTER_BGM_VOL:
				//boost::python::call_method<void>(self, "onPacket", header, (Packets::GCCharacterBGMVol*) packet);
                break;
            case GC_QUICKSLOT_ADD:
				//boost::python::call_method<void>(self, "onPacket", header, (Packets::GCQuickslotAdd*) packet);
                break;
            case GC_POINTS:
				//boost::python::call_method<void>(self, "onPacket", header, (Packets::GCPoints*) packet);
                break;
            case GC_SKILL_LEVEL:
				// //boost::python::call_method<void>(self, "onPacket", header, (Packets::GCSkillLevel*) packet);
                break;
            case GC_ITEM_SET:
				//boost::python::call_method<void>(self, "onPacket", header, (Packets::GCItemSet*) packet);
                break;
            case GC_ITEM_UPDATE:
				//boost::python::call_method<void>(self, "onPacket", header, (Packets::GCItemUpdate*) packet);
                break;
            case GC_CHARACTER_ADD:
				//boost::python::call_method<void>(self, "onPacket", header, (Packets::GCCharacterAdd*) packet);
                break;
            case GC_CHARACTER_ADDITIONAL_INFO:
				//boost::python::call_method<void>(self, "onPacket", header, (Packets::GCCharacterAdditionalInfo*) packet);
                break;
            case GC_NPC_POSITION:
				//boost::python::call_method<void>(self, "onPacket", header, (Packets::GCNPCPosition*) packet);
                break;
            case GC_CHARACTER_UPDATE:
				//boost::python::call_method<void>(self, "onPacket", header, (Packets::GCCharacterUpdate*) packet);
                break;
            case GC_AFFECT_ADD:
				//boost::python::call_method<void>(self, "onPacket", header, (Packets::GCAffectAdd*) packet);
                break;
            case GC_MOVE:
				//boost::python::call_method<void>(self, "onPacket", header, (Packets::GCMove*) packet);
                break;
            case GC_GUILD:
				//boost::python::call_method<void>(self, "onPacket", header, (Packets::GCGuild*) packet);
                break;
            case GC_WALK_MODE:
				//boost::python::call_method<void>(self, "onPacket", header, (Packets::GCWalkMode*) packet);
                break;
            case GC_LAND_LIST:
				//boost::python::call_method<void>(self, "onPacket", header, (Packets::GCLandList*) packet);
                break;
            case GC_TIME:
				//boost::python::call_method<void>(self, "onPacket", header, (Packets::GCTime*) packet);
                break;
            case GC_CHANNEL:
				//boost::python::call_method<void>(self, "onPacket", header, (Packets::GCChannel*) packet);
                break;
            case GC_CHAT:
				//boost::python::call_method<void>(self, "onPacket", header, (Packets::GCChat*) packet);
                break;
            case GC_AFFECT_REMOVE:
				//boost::python::call_method<void>(self, "onPacket", header, (Packets::GCAffectRemove*) packet);
                break;
            case GC_WHISPER:
                //boost::python::call_method<void>(self, "onPacket", header, (Packets::GCWhisper*) packet);
                break;
            case GC_OWNERSHIP:
                //boost::python::call_method<void>(self, "onPacket", header, (Packets::GCOwnership*) packet);
                break;
            case GC_STUN:
                //boost::python::call_method<void>(self, "onPacket", header, (Packets::GCStun*) packet);
                break;
            case GC_CREATE_FLY:
                //boost::python::call_method<void>(self, "onPacket", header, (Packets::GCCreateFly*) packet);
                break;
            case GC_DEAD:
                //boost::python::call_method<void>(self, "onPacket", header, (Packets::GCDead*) packet);
                break;
            case GC_CHARACTER_DELETE:
                //boost::python::call_method<void>(self, "onPacket", header, (Packets::GCCharacterDelete*) packet);
                break;
            case GC_ITEM_GROUND_ADD:
                //boost::python::call_method<void>(self, "onPacket", header, (Packets::GCItemGroundAdd*) packet);
                break;
            case GC_ITEM_GROUND_DEL:
                //boost::python::call_method<void>(self, "onPacket", header, (Packets::GCItemGroundDel*) packet);
                break;
            case GC_PVP:
                //boost::python::call_method<void>(self, "onPacket", header, (Packets::GCPVP*) packet);
                break;
            case GC_SCRIPT:
                //boost::python::call_method<void>(self, "onPacket", header, (Packets::GCScript*) packet);
                break;
            case GC_QUEST_INFO:
                //boost::python::call_method<void>(self, "onPacket", header, (Packets::GCQuestInfo*) packet);
                break;
            case GC_WARP:
                //boost::python::call_method<void>(self, "onPacket", header, (Packets::GCWarp*) packet);
                break;
            case GC_ITEM_OWNERSHIP:
                //boost::python::call_method<void>(self, "onPacket", header, (Packets::GCItemOwnership*) packet);
                break;
            case GC_FISHING:
                //boost::python::call_method<void>(self, "onPacket", header, (Packets::GCFishing*) packet);
                break;
            case GC_FLY_TARGETING:
                //boost::python::call_method<void>(self, "onPacket", header, (Packets::GCFlyTargeting*) packet);
                break;
            case GC_CHARACTER_CREATE_SUCCESS:
                //boost::python::call_method<void>(self, "onPacket", header, (Packets::GCCharacterCreateSuccess*) packet);
                break;
            case GC_EXCHANGE:
                //boost::python::call_method<void>(self, "onPacket", header, (Packets::GCExchange*) packet);
                break;
            default:
               Logger::getInstance()->warn("Header %i isn't implemented in ListenerModule!", header);
                break;
        }

        //boost::python::call_method<void>(self, "onPacket", header);

    } catch (...) {
       
    }
}

// Call every known listener
void ListenerModule::callListenerFunctions(uint8 header, void* packet) {
    for(std::vector<ListenerModule*>::iterator it = listeners.begin(); it != listeners.end(); ++it) {
        ListenerModule* module = *it;
        if(module == nullptr) {
            Logger::getInstance()->fatal("Failed to call listener due to nullptr");
            continue;
        }
        module->callListenerFunction(header, packet);
    }
}



std::vector<ListenerModule*> ListenerModule::listeners = std::vector<ListenerModule*>();

