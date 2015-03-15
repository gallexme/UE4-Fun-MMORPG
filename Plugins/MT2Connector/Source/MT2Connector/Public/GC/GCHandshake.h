#pragma once


#include"M2CL/Core/Types.h"

#define GC_HANDSHAKE 255


   
        
           
#pragma pack(1)
                struct GCHandshake {
                    uint8 header;
					uint32 handshake;
					uint32 time;
					int32 delta;
                };
#pragma pack()
      