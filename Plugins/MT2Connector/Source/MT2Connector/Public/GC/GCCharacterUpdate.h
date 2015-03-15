#pragma once

#include"M2CL/Core/Types.h"

#define GC_CHARACTER_UPDATE 19


   
        
           
#pragma pack(1)
                struct GCCharacterUpdate {
                    uint8 header;
                    uint32 vid;
                    uint16 part[CHR_EQUIPPART_MAX_NUM];
                    uint8 movingSpeed;
                    uint8 attackSpeed;
                    uint8 stateFlag;
                    uint32 affectFlag[2];
                    uint32 guildId;
                    uint16 alignment;
                    uint8 pkMode;
                    uint32 mountVnum;

                    uint16 getPart(int32 id) { return part[id]; }

                    uint32 getAffectFlag(uint8 id) {
                        return affectFlag[id];
                    }
                };
#pragma pack()
