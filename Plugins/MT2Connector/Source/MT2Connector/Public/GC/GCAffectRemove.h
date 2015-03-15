#pragma once


#include"M2CL/Core/Types.h"

#define GC_AFFECT_REMOVE 127


   
        
           
#pragma pack(1)
                struct GCAffectRemove {
                    uint8 header;
                    uint32 type;
                    uint8 applyOn;
                };
#pragma pack()
   