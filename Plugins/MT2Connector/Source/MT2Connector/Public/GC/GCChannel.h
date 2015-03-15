#pragma once


#include"M2CL/Core/Types.h"

#define GC_CHANNEL 121


   
        
           
#pragma pack(1)
                struct GCChannel {
                    uint8 header;
                    uint8 channel;
                };
#pragma pack()
 