#pragma once

#include"M2CL/Core/Types.h"

#define GC_ITEM_GROUND_ADD 26


   
        
           
#pragma pack(1)
                struct GCItemGroundAdd {
                    uint8 header;
                    int32 x, y, z;
                    uint32 vid;
                    uint32 vnum;
                };
#pragma pack()
     
     