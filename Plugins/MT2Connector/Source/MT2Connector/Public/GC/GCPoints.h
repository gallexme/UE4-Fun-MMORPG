#pragma once

#include"M2CL/Core/Types.h"

#define GC_POINTS 16


   
        
           
#pragma pack(1)
                struct GCPoints {
					uint8 header;
					int32 points[POINT_MAX_NUM];

                    int32 getPoint(uint8 i) {
                        return points[i];
                    }
                };
#pragma pack()
          