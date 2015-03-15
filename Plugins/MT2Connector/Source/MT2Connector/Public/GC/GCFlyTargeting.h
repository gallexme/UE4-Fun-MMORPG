#pragma once


#include"M2CL/Core/Types.h"

#define GC_FLY_TARGETING 71


   
        
           
#pragma pack(1)
                struct GCFlyTargeting {
                    uint8 header;
                    uint32 shooterVID;
                    uint32 targetVID;
                    int32 x;
                    int32 y;
                };
#pragma pack()
    