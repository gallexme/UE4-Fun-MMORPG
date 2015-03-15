#pragma once

#include "GC/GCHandshake.h"
#include "GC/GCKeyAgreementCompleted.h"
#include "GC/GCKeyAgreement.h"
#include "GC/GCPhase.h"
#include "GC/GCPing.h"
#include "GC/GCLoginFailure.h"
#include "GC/GCAuthSuccess.h"
#include "GC/GCHybridCryptKeys.h"
#include "GC/GCEmpire.h"
#include "GC/GCLoginSuccess.h"
#include "GC/GCPointChange.h"
#include "GC/GCCharacterBGMVol.h"
#include "GC/GCChat.h"
#include "GC/GCQuickslotAdd.h"
#include "GC/GCPoints.h"
#include "GC/GCSkillLevel.h"
#include "GC/GCItemSet.h"
#include "GC/GCItemUpdate.h"
#include "GC/GCCharacterAdd.h"
#include "GC/GCCharacterAdditionalInfo.h"
#include "GC/GCNPCPosition.h"
#include "GC/GCCharacterUpdate.h"
#include "GC/GCAffectAdd.h"
#include "GC/GCMove.h"
#include "GC/GCGuild.h"
#include "GC/GCWalkMode.h"
#include "GC/GCLandList.h"
#include "GC/GCTime.h"
#include "GC/GCChannel.h"
#include "GC/GCAffectRemove.h"
#include "GC/GCWhisper.h"
#include "GC/GCOwnership.h"
#include "GC/GCStun.h"
#include "GC/GCCreateFly.h"
#include "GC/GCDead.h"
#include "GC/GCCharacterDelete.h"
#include "GC/GCItemGroundAdd.h"
#include "GC/GCItemGroundDel.h"
#include "GC/GCPVP.h"
#include "GC/GCScript.h"
#include "GC/GCQuestInfo.h"
#include "GC/GCWarp.h"
#include "GC/GCItemOwnership.h"
#include "GC/GCFishing.h"
#include "GC/GCFlyTargeting.h"
#include "GC/GCCharacterCreateSuccess.h"
#include "GC/GCExchange.h"

#include "CG/CGLogin2.h"
#include "CG/CGLogin3.h"
#include "CG/CGPong.h"
#include "CG/CGCharacterSelect.h"
#include "CG/CGEnterGame.h"
#include "CG/CGClientVersion.h"
#include "CG/CGClientVersion2.h"
#include "CG/CGCharacterCreate.h"
#include "CG/CGEmpire.h"
#include "CG/CGItemPickup.h"
#include "CG/CGExchange.h"
#include "CG/CGMove.h"

#include <string>

#include "../../Types.h"


class Packets {
public:
	static std::string getGCPacketName(uint8 header);
	static std::string getCGPacketName(uint8 header);
	static bool hasCGPacketSequence(uint8 header);
private:
	static void init();
private:
	static std::map<uint8, std::string> gcPacketNames;
	static std::map<uint8, std::string> cgPacketNames;
	static std::map<uint8, bool> cgHasSequences;

	static bool isInit;
};

