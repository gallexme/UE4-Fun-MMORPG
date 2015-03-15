#pragma once

#include"M2CL/Core/Types.h"
#define GC_WALK_MODE 111


   
        
           
#pragma pack(1)
                struct GCWalkMode {
                    uint8 header;
                    uint32 vid;
                    uint8 mode;
                };
#pragma pack()
        