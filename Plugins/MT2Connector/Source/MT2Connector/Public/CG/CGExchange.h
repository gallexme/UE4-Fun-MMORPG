#pragma once

#include"M2CL/Core/Types.h"

#define CG_EXCHANGE 27


   
        
           
#pragma pack(1)
                struct CGExchange {
                    uint8 header;
                    uint8 subHeader;
                    uint32 arg1;
                    uint8 arg2;
                    ItemPos pos;
                };
#pragma pack()
     
