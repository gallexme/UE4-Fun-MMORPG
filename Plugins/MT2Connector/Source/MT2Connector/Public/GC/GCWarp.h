#pragma once

#include"M2CL/Core/Types.h"
#define GC_WARP 65


   
        
           
#pragma pack(1)
                struct GCWarp {
                    uint8 header;
                    int32 x;
                    int32 y;
                    int32 addr;
                    uint16 port;
                };
#pragma pack()
   