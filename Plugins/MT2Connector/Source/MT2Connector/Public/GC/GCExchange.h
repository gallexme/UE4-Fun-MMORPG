#pragma once

#include"M2CL/Core/Types.h"

#define GC_EXCHANGE 42


   
        
           
#pragma pack(1)
                struct GCExchange {
                    uint8 header;
                    uint8 subHeader;
                    uint8 isMe;
                    uint32 arg1;
                    ItemPos arg2;
                    uint32 arg3;
                    int32 sockets[ITEM_SOCKET_MAX_NUM];
                    PlayerItemAttribute attrs[ITEM_ATTRIBUTE_MAX_NUM];

                    int32 getSocket(uint8 index) {
                        return sockets[index];
                    }

                    PlayerItemAttribute getAttr(uint8 index) {
                        return attrs[index];
                    }
                };
#pragma pack()
       