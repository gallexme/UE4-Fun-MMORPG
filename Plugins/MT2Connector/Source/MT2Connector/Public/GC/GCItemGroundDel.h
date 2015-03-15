#pragma once


#include"M2CL/Core/Types.h"
#define GC_ITEM_GROUND_DEL 27

#pragma pack(1)
struct GCItemGroundDel {
	uint8 header;
	uint32 vid;
};
#pragma pack()
