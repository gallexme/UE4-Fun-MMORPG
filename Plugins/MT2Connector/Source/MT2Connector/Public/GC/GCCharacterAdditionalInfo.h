#pragma once

#include"M2CL/Core/Types.h"

#define GC_CHARACTER_ADDITIONAL_INFO 136


   
        
           
#pragma pack(1)
                struct GCCharacterAdditionalInfo {
                    uint8 header;
                    uint32 vid;
                    char name[CHARACTER_NAME_MAX_LEN + 1];
                    uint16 part[CHR_EQUIPPART_MAX_NUM];
                    uint8 empire;
                    uint32 guildId;
                    uint32 level;
                    uint16 alignment;
                    uint8 pkMode;
                    uint32 mountVnum;

                    std::string getName() { return name; }
                    uint16 getPart(int32 id) { return part[id]; }
                };
#pragma pack()
    