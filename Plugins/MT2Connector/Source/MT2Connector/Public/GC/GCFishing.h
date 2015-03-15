#pragma once

#include"M2CL/Core/Types.h"

#define GC_FISHING 89


   
        
           
#pragma pack(1)
                struct GCFishing {
                    uint8 header;
                    uint8 subheader;
                    uint32 info;
                    uint8 dir;
                };
#pragma pack()
        