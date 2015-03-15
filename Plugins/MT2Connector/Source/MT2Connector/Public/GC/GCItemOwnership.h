#pragma once

#include"M2CL/Core/Types.h"

#define GC_ITEM_OWNERSHIP 31


   
        
           
#pragma pack(1)
                struct GCItemOwnership {
                    uint8 header;
                    uint32 vid;
                    char name[CHARACTER_NAME_MAX_LEN + 1];

                    std::string getName() { return name; }
                };
#pragma pack()
