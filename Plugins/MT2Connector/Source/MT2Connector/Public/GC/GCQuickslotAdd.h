#pragma once


#include"M2CL/Core/Types.h"

#define GC_QUICKSLOT_ADD 28


   
        
           
#pragma pack(1)
                struct GCQuickslotAdd {
					uint8 header;
					uint8 pos;
                    Quickslot slot;
                };
#pragma pack()
