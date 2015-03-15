#pragma once


#include"M2CL/Core/Types.h"

#define GC_MOVE 3


   
        
           
#pragma pack(1)
                struct GCMove {
                    uint8 header;
                    uint8 func;
                    uint8 arg;
                    uint8 rot;
                    uint32 vid;
                    int32 x;
                    int32 y;
                    uint32 time;
                    uint32 duration;
                };
#pragma pack()
       