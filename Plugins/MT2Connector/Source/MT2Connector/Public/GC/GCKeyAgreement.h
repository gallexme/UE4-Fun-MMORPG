#pragma once

#include"M2CL/Core/Types.h"

#define GC_KEYAGREEMENT 251


   
        
           
#pragma pack(1)
                struct GCKeyAgreement {
                    uint8 header;
					uint16 agreedLength;
					uint16 dataLength;
                    char data[256];
                };
#pragma pack()
   