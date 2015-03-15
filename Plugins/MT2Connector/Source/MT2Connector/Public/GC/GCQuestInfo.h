#pragma once

#include"M2CL/Core/Types.h"

#define GC_QUEST_INFO 81


   
        
           
#pragma pack(1)
                struct GCQuestInfo {
                    uint8 header;
                    uint16 size;
                    uint16 index;
                    uint8 flag;
                };
#pragma pack()
        