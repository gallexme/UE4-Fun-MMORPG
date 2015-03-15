#pragma  once 
#include <map>
#include <vector>
#include <string>
#include "Types.generated.h"
enum {
    CHARACTER_NAME_MAX_LEN = 24,
    POINT_MAX_NUM = 255,
    SKILL_MAX_NUM = 255,
    ITEM_SOCKET_MAX_NUM = 3,
    ITEM_ATTRIBUTE_MAX_NUM = 7,
    CHR_EQUIPPART_MAX_NUM = 4,
};



#pragma pack(1)
USTRUCT()
typedef struct SSimplePlayer {
	GENERATED_USTRUCT_BODY();
    uint32 id;
    char name[CHARACTER_NAME_MAX_LEN + 1];
	uint8 job;
	uint8 level;
	uint32 playMinutes;
	uint8 st, ht, dx, iq;
	uint16 mainPart;
	uint8 changeName;
	uint16 hairPart;
	uint8 dummy[4];
	int32 x, y;
    int32 addr;
    uint16 port;
	uint8 skillGroup;

    std::string getName() { return name; }
} SimplePlayer;
USTRUCT()
typedef struct SQuickslot {
	GENERATED_USTRUCT_BODY();
	uint8 type;
	uint8 pos;
} Quickslot;
USTRUCT()
typedef struct SPlayerSkill {
	GENERATED_USTRUCT_BODY();
	uint8 masterType;
	uint8 level;
	int32 nextRead;
} PlayerSkill;
USTRUCT()
typedef struct SItemPos {
	GENERATED_USTRUCT_BODY();
	uint8 windowType;
	uint16 cell;
} ItemPos;
USTRUCT()
typedef struct SPlayerItemAttribute {
	GENERATED_USTRUCT_BODY();
    uint8 type;
	int16 value;
} PlayerItemAttribute;
USTRUCT()
typedef struct SNPCPosition {
	GENERATED_USTRUCT_BODY();
	uint8 type;
    char name[CHARACTER_NAME_MAX_LEN + 1];
	int32 x;
    int32 y;

    std::string getName() { return name; }
} NPCPosition;
USTRUCT()
typedef struct SPacketAffectElement {
	GENERATED_USTRUCT_BODY();
    uint32 type;
	uint8 applyOn;
	int32 applyValue;
    uint32 flag;
    int32 duration;
    int32 spCost;
} PacketAffectElement;
USTRUCT()
typedef struct SPacketLandListElement {
	GENERATED_USTRUCT_BODY();
	uint32 id;
	int32 x;
	int32 y;
	int32 width;
	int32 height;
	uint32 guildID;
} PacketLandListElement;
#pragma pack()

