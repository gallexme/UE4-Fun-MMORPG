#pragma once

#include"M2CL/Core/Types.h"

#define GC_TIME 106


   
        
           
#pragma pack(1)
                struct GCTime {
                    uint8 header;
                    int32 time;
                };
#pragma pack()
        