#pragma once


#include"M2CL/Core/Types.h"

#define GC_GUILD 75


   
        
           
#pragma pack(1)
                struct GCGuild {
                    uint8 header;
                    uint16 size;
                    uint8 subheader;
                    void* subpacket;
                };
#pragma pack()
