#pragma once


#include"M2CL/Core/Types.h"

#define GC_WHISPER 34


   
        
           
#pragma pack(1)
                struct GCWhisper {
                    uint8 header;
                    uint16 size;
                    uint8 type;
                    char nameFrom[CHARACTER_NAME_MAX_LEN + 1];
                    char text[1];

                    std::string getNameFrom() { return nameFrom; }
                    std::string getText() { return text; }
                };
#pragma pack()
       