#pragma once

#include"M2CL/Core/Types.h"

#define GC_SCRIPT 45

#include <string>


   
        
           
#pragma pack(1)
                struct GCScript {
                    uint8 header;
                    uint16 size;
                    uint8 skin;
                    uint16 src_size;
                    uint8 questFlag;
                    char script[1];

                    std::string getScript() {
                        std::string ret = script;
                        ret.push_back('\0');
                        return ret;
                    }
                };
#pragma pack()
    