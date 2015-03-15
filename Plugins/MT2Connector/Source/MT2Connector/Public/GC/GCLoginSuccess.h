#pragma once

#include"M2CL/Core/Types.h"

#define GC_LOGIN_SUCCESS 32


   
        
           
#pragma pack(1)
                struct GCLoginSuccess {
					uint8 header;
                    SimplePlayer players[4];
                    uint32 guildId[4];
                    char guildName[4][13];

					uint32 handle;
					uint32 randomKey;

                    SimplePlayer getPlayer(int32 id) {
                        return players[id];
                    }

                    uint32 getGuildId(int32 id) {
                        return guildId[id];
                    }

                    std::string getGuildName(int32 id) {
                        return guildName[id];
                    }
                };
#pragma pack()
      