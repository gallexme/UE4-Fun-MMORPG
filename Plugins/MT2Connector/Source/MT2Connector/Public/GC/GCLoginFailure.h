#pragma once

#include"M2CL/Core/Types.h"

#define GC_LOGIN_FAILURE 7


   
        
           
#pragma pack(1)
                struct GCLoginFailure {
					uint8 header;
                    char status[9];

                    std::string getStatus() { return status; }
                };
#pragma pack()
       