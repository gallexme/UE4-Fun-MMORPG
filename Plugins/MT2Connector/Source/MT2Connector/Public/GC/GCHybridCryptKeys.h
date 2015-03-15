#pragma once

#include"M2CL/Core/Types.h"

#define GC_HYBRID_CRYPT_KEYS 152


   
        
           
#pragma pack(1)
                struct GCHybridCryptKeys {
					uint8 header;
					int16 dynamicPacketSize;
                    int32 keyStreamLen;
					uint8* dataKeyStream;
                };
#pragma pack()
