#pragma once

#include"M2CL/Core/Logger.h"

#define CG_MOVE 7


   
        
           
#pragma pack(1)
                struct CGMove {
                    uint8 header;
                    uint8 func;
                    uint8 arg;
                    uint8 rot;
                    int32 x;
                    int32 y;
                    uint32 time;
                };
#pragma pack()
          
