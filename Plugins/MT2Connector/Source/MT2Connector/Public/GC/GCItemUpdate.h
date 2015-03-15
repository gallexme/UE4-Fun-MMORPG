#pragma once


#include"M2CL/Core/Types.h"

#define GC_ITEM_UPDATE 25


   
        
           
#pragma pack(1)
                struct GCItemUpdate {
                    uint8 header;
                    ItemPos cell;
                    uint8 count;
                    int32 sockets[ITEM_SOCKET_MAX_NUM];
                    PlayerItemAttribute attr[ITEM_ATTRIBUTE_MAX_NUM];

                    int32 getSocket(uint8 socket) {
                        return sockets[socket];
                    }

                    PlayerItemAttribute getAttr(uint8 id) {
                        return attr[id];
                    }
                };
#pragma pack()
        