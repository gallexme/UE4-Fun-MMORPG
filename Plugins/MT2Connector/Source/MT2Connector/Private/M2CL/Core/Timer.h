#pragma once

#include <chrono>


        class Timer {
        public:
            Timer();
            ~Timer();

            void setServerTime(uint32 time);
            uint32 getServerTime();

            static Timer* getInstance() {
                if(instance == nullptr) {
                    new Timer();
                }

                return instance;
            }

        private:
            uint32 serverTime;
            std::chrono::high_resolution_clock::time_point startTime;

            static Timer* instance;

            uint32 time;

        };

