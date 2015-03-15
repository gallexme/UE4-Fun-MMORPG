#pragma once

#include"M2CL/Core/Types.h"

#define GC_POINT_CHANGE 17


   
        
           
#pragma pack(1)
                struct GCPointChange {
                    int32 header;
                    uint32 vid;
                    uint8 type;
                    int32 amount;
					int32 value;
                };
#pragma pack()
          