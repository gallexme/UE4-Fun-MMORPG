#pragma once


#include"M2CL/Core/Types.h"
#include "MT2ConnectorPrivatePCH.h"
#define CG_CHARACTER_CREATE 4


#pragma pack(1)
					
                struct CGCharacterCreate {
                    uint8 header;
                    uint8 slot;
                    char name[CHARACTER_NAME_MAX_LEN + 1];
                    uint16 job;
                    uint8 shape;
                    uint8 Con;
                    uint8 Int;
                    uint8 Str;
                    uint8 Dex;

                    std::string getName() { return name; }

                    void setName(const std::string nName) {
                        if(nName.size() >= sizeof(this->name))
                            throw std::exception();
                        strncpy(this->name, nName.c_str(), nName.size());
                    }
                };
#pragma pack()
