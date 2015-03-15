#pragma once


#include"M2CL/Core/Types.h"

#define GC_AUTH_SUCCESS 150


   
        
           
#pragma pack(1)
                struct GCAuthSuccess {
					uint8 header;
					uint32 loginKey;
					uint8 result;
                };
#pragma pack()
 