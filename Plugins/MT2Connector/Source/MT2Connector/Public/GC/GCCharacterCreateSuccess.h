#pragma once


#include"M2CL/Core/Types.h"

#define GC_CHARACTER_CREATE_SUCCESS 8


   
        
           
#pragma pack(1)
                struct GCCharacterCreateSuccess {
                    uint8 header;
                    uint8 slot;
                    SimplePlayer player;
                };
#pragma pack()
       