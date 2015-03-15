#pragma once


#include"M2CL/Core/Types.h"

#define GC_CHARACTER_BGM_VOL 138


   
        
           
#pragma pack(1)
                struct GCCharacterBGMVol {
                    uint8 header;
                    uint32 vid;
                    uint16 raceNum;
                    char charName[CHARACTER_NAME_MAX_LEN + 1];
                    char bgmName[25];
                    float bgmVol;
					uint8 x, y, z;
					uint8 empire;
					uint8 skillGroup;

                    std::string getCharName() { return charName; }
                    std::string getBGMName() { return bgmName; }
                };
#pragma pack()
 