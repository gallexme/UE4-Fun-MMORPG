#pragma once

#include"M2CL/Core/Logger.h"

#define GC_CHARACTER_DELETE 2


   
        
           
#pragma pack(1)
                struct GCCharacterDelete {
                    uint8 header;
                    uint32 vid;
                };
#pragma pack()
