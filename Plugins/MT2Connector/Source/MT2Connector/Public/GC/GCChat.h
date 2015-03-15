#pragma once


#include"M2CL/Core/Types.h"

#define GC_CHAT 4


   
        
           
#pragma pack(1)
                struct GCChat {
					uint8 header;
					int16 size;
					uint8 type;
                    uint32 id;
					uint8 empire;
                    char text[1];
                };
#pragma pack()
      