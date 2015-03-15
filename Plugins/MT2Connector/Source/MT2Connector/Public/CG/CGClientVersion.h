#pragma once

#include"M2CL/Core/Types.h"
#include "MT2ConnectorPrivatePCH.h"
#define CG_CLIENT_VERSION 253


#pragma pack(1)
					
                struct CGClientVersion {
                    uint8 header;
                    char filename[32+1];
                    char timestamp[32+1];

                    std::string getFileName() { return filename; }
                    std::string getTimeStamp() { return timestamp; }

                    void setFileName(const std::string nFilename) {
                        if(nFilename.size() >= sizeof(this->filename))
                            throw std::exception();
                        strncpy(this->filename, nFilename.c_str(), nFilename.size());
                    }

                    void setTimeStamp(const std::string nTimestamp) {
                        if(nTimestamp.size() >= sizeof(this->timestamp))
                            throw std::exception();
                        strncpy(this->timestamp, nTimestamp.c_str(), nTimestamp.size());
                    }
                };
#pragma pack()
  