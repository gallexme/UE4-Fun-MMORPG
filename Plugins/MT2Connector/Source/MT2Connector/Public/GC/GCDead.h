#pragma once


#include"M2CL/Core/Types.h"

#define GC_DEAD 14


   
        
           
#pragma pack(1)
                struct GCDead {
                    uint8 header;
                    uint32 vid;
                };
#pragma pack()
     