#pragma once


#include"M2CL/Core/Types.h"

#define GC_LAND_LIST 130


   
        
           
#pragma pack(1)
                struct GCLandList {
                    uint8 header;
                    uint16 size;
                    PacketLandListElement* elements;

                    PacketLandListElement getElement(int32 id) {
                        return elements[id];
                    }
                };
#pragma pack()
          