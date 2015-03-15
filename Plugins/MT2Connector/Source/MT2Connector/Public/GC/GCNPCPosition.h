#pragma once

#include"M2CL/Core/Types.h"

#define GC_NPC_POSITION 115


   
        
           
#pragma pack(1)
                struct GCNPCPosition {
                    uint8 header;
                    uint16 size;
                    uint16 count;

                    NPCPosition* npcPositions;

                    NPCPosition getNPCPosition(uint16 id) {
                        return npcPositions[id];
                    }
                };
#pragma pack()
          