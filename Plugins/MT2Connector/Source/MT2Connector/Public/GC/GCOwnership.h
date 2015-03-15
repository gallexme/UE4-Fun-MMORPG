#pragma once

#include"M2CL/Core/Types.h"

#define GC_OWNERSHIP 62


   
        
           
#pragma pack(1)
                struct GCOwnership {
                    uint8 header;
                    uint32 ownerVID;
                    uint32 victimVID;
                };
#pragma pack()
         