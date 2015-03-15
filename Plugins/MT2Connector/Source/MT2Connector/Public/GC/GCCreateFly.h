#pragma once

#include"M2CL/Core/Types.h"

#define GC_CREATE_FLY 70


   
        
           
#pragma pack(1)
                struct GCCreateFly {
                    uint8 header;
                    uint8 type;
                    uint32 startVID;
                    uint32 endVID;
                };
#pragma pack()
   