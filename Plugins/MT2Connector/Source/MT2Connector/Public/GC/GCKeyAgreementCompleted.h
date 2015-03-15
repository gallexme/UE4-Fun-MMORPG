#pragma once

#include"M2CL/Core/Types.h"

#define GC_KEYAGREEMENT_COMPLETED 250


   
        
           
#pragma pack(1)
                struct GCKeyAgreementCompleted {
					uint8 header;
					uint8 data[3]; // not used
                };
#pragma pack()
