#pragma once


#include"M2CL/Core/Types.h"

#define GC_AFFECT_ADD 126


   
        
           
#pragma pack(1)
                struct GCAffectAdd {
                    uint8 header;
                    PacketAffectElement elem;
                };
#pragma pack()
         