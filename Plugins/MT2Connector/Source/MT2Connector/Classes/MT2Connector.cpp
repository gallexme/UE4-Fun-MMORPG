#include "MT2ConnectorPrivatePCH.h"
#include"MT2Connector.h"


#include "MT2ClientThread.h"
AMT2Connector::AMT2Connector()
{

}


void AMT2Connector::ConnectToServer(FString authIP, int32 authPort, FString channelIP, int32 channelPort)
{

	FMT2ClientThread::JoyInit(authIP, authPort, channelIP, channelPort, this);
}

void  AMT2Connector::ConnectToChannel(FString channelIP, int32 channelPort) {
	FMT2ClientThread::connect(channelIP, channelPort);
}

void AMT2Connector::Login(FString username, FString password)
{

	FCGLogin3* packet = new FCGLogin3();
	packet->header = CG_LOGIN3;
	packet->setLogin(username);
	packet->setPassword(password);
	FMT2ClientThread::send(packet, sizeof(*packet));
}

void AMT2Connector::SendLoginKey(FString username, int32 loginKey)
{
	CGLogin2* packet = new CGLogin2();
	packet->header = CG_LOGIN2;
	packet->setLogin(username);
	packet->loginKey = loginKey;
	FMT2ClientThread::send(packet, sizeof(*packet));
}

void AMT2Connector::OnPacket(uint8 header, void* packet)
{
	switch (header) {
	case GC_HANDSHAKE:
		this->OnPacketLog("GC_HANDSHAKE");
		break;
	case GC_KEYAGREEMENT:
		this->OnPacketLog("GC_KEYAGREEMENT");
		break;
	case GC_KEYAGREEMENT_COMPLETED:
		this->OnPacketLog("GC_KEYAGREEMENT_COMPLETED");
		break;
	case GC_PHASE:
		this->OnPacketLog("GC_PHASE");
		break;
	case GC_PING:
		this->OnPacketLog("GC_PING");
		break;
	case GC_LOGIN_FAILURE:
		this->OnPacketLog("GC_LOGIN_FAILURE");
		break;
	case GC_AUTH_SUCCESS:
		GCAuthSuccess* result;
		result = (GCAuthSuccess*)packet;
		this->OnLoginSuccess(result->loginKey, result->result);
		this->OnPacketLog("GC_AUTH_SUCCESS");
		break;
	case GC_HYBRID_CRYPT_KEYS:
		this->OnPacketLog("GC_HYBRID_CRYPT_KEYS");
		break;
	case GC_EMPIRE:
		this->OnPacketLog("GC_EMPIRE");
		break;
	case GC_LOGIN_SUCCESS:
		GCLoginSuccess* result;
		result = (GCLoginSuccess*)packet;
		this->OnCharacterSelect(result->loginKey, result->result);
		this->OnPacketLog("GC_LOGIN_SUCCESS");
		break;
	case GC_POINT_CHANGE:
		this->OnPacketLog("GC_POINT_CHANGE");
		break;
	case GC_CHARACTER_BGM_VOL:
		this->OnPacketLog("GC_CHARACTER_BGM_VOL");
		break;
	case GC_QUICKSLOT_ADD:
		this->OnPacketLog("GC_QUICKSLOT_ADD");
		break;
	case GC_POINTS:
		this->OnPacketLog("GC_POINTS");
		break;
	case GC_SKILL_LEVEL:
		this->OnPacketLog("GC_SKILL_LEVEL");
		break;
	case GC_ITEM_SET:
		this->OnPacketLog("GC_ITEM_SET");
		break;
	case GC_ITEM_UPDATE:
		this->OnPacketLog("GC_ITEM_UPDATE");
		break;
	case GC_CHARACTER_ADD:
		this->OnPacketLog("GC_CHARACTER_ADD");
		break;
	case GC_CHARACTER_ADDITIONAL_INFO:
		this->OnPacketLog("GC_CHARACTER_ADDITIONAL_INFO");
		break;
	case GC_NPC_POSITION:
		this->OnPacketLog("GC_NPC_POSITION");
		break;
	case GC_CHARACTER_UPDATE:
		this->OnPacketLog("GC_CHARACTER_UPDATE");
		break;
	case GC_AFFECT_ADD:
		this->OnPacketLog("GC_AFFECT_ADD");
		break;
	case GC_MOVE:
		this->OnPacketLog("GC_MOVE");
		break;
	case GC_GUILD:
		this->OnPacketLog("GC_GUILD");
		break;
	case GC_WALK_MODE:
		this->OnPacketLog("GC_WALK_MODE");
		break;
	case GC_LAND_LIST:
		this->OnPacketLog("GC_LAND_LIST");
		break;
	case GC_TIME:
		this->OnPacketLog("GC_TIME");
		break;
	case GC_CHANNEL:
		this->OnPacketLog("GC_CHANNEL");
		break;
	case GC_CHAT:
		this->OnPacketLog("GC_CHAT");
		break;
	case GC_AFFECT_REMOVE:
		this->OnPacketLog("GC_AFFECT_REMOVE");
		break;
	case GC_WHISPER:
		this->OnPacketLog("GC_WHISPER");
		break;
	case GC_OWNERSHIP:
		this->OnPacketLog("GC_OWNERSHIP");
		break;
	case GC_STUN:
		this->OnPacketLog("GC_STUN");
		break;
	case GC_CREATE_FLY:
		this->OnPacketLog("GC_CREATE_FLY");
		break;
	case GC_DEAD:
		this->OnPacketLog("GC_DEAD");
		break;
	case GC_CHARACTER_DELETE:
		this->OnPacketLog("GC_CHARACTER_DELETE");
		break;
	case GC_ITEM_GROUND_ADD:
		this->OnPacketLog("GC_ITEM_GROUND_ADD");
		break;
	case GC_ITEM_GROUND_DEL:
		this->OnPacketLog("GC_ITEM_GROUND_DEL");
		break;
	case GC_PVP:
		this->OnPacketLog("GC_PVP");
		break;
	case GC_SCRIPT:
		this->OnPacketLog("GC_SCRIPT");
		break;
	case GC_QUEST_INFO:
		this->OnPacketLog("GC_QUEST_INFO");
		break;
	case GC_WARP:
		this->OnPacketLog("GC_WARP");
		break;
	case GC_ITEM_OWNERSHIP:
		this->OnPacketLog("GC_ITEM_OWNERSHIP");
		break;
	case GC_FISHING:
		this->OnPacketLog("GC_FISHING");
		break;
	case GC_FLY_TARGETING:
		this->OnPacketLog("GC_FLY_TARGETING");
		break;
	case GC_CHARACTER_CREATE_SUCCESS:
		this->OnPacketLog("GC_CHARACTER_CREATE_SUCCESS");
		break;
	case GC_EXCHANGE:
		this->OnPacketLog("GC_EXCHANGE");
		break;
	default:
		break;
	}
}


