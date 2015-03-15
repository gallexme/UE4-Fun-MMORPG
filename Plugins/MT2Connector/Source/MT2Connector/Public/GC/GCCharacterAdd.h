#pragma once

#include"M2CL/Core/Logger.h"

#define GC_CHARACTER_ADD 1


   
        
           
#pragma pack(1)
                struct GCCharacterAdd {
                    uint8 header;
                    uint32 vid;

                    float angle;
                    int32 x;
                    int32 y;
                    int32 z;

                    uint8 type;
                    uint16 raceNum;
                    uint8 movingSpeed;
                    uint8 attackSpeed;

                    uint8 stateFlag;
                    uint32 affectFlag[2];

                    uint32 getAffectFlag(uint8 id) {
                        return affectFlag[id];
                    }
                };
#pragma pack()
        