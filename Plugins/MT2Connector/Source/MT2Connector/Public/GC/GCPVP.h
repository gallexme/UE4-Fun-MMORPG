#pragma once

#include"M2CL/Core/Types.h"

#define GC_PVP 41


   
        
           
#pragma pack(1)
                struct GCPVP {
                    uint8 header;
                    uint32 vidSrc;
                    uint32 vidDst;
                    uint8 mode;
                };
#pragma pack()
			