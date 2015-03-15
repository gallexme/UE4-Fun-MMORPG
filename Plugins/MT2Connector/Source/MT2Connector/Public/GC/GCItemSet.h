#pragma once

#include"M2CL/Core/Types.h"

#define GC_ITEM_SET 21


   
        
           
#pragma pack(1)
                struct GCItemSet {
					uint8 header;
                    ItemPos cell;
					uint32 vnum;
					uint8 count;
					uint32 flags;
					uint32 antiFlags;
                    bool highlight;
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
   