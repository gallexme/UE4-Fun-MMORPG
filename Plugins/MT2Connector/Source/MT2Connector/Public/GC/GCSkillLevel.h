#pragma once


#include"M2CL/Core/Types.h"

#define GC_SKILL_LEVEL 76


   
        
           
#pragma pack(1)
                struct GCSkillLevel {
					uint8 header;
                    PlayerSkill skills[SKILL_MAX_NUM];

                    PlayerSkill getSkill(uint8 id) {
                        return skills[id];
                    }
                };
#pragma pack()
         