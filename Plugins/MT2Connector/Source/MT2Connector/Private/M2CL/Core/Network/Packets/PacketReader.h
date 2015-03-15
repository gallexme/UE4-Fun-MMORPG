#pragma once

#include <vector>

#include "../../Types.h"

                class PacketReader{
                public:
                    PacketReader();
                    ~PacketReader();

                    int32 getEstimatedPacketSize(uint8 header);
                    void* getPacket(uint8 header, std::vector<uint8> data);
                };
 
