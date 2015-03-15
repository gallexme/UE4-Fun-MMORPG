#include "MT2ConnectorPrivatePCH.h"
#include "Timer.h"

#include <iostream>


Timer::Timer() {
    instance = this;

    startTime = std::chrono::high_resolution_clock::now();
}

Timer::~Timer() {

}

void Timer::setServerTime(uint32 time) {
    serverTime = time;

    startTime = std::chrono::high_resolution_clock::now();
}

uint32 Timer::getServerTime() {
    uint32 delta = 0;
    auto endTime = std::chrono::high_resolution_clock::now();
    auto time = endTime - startTime;
    delta = std::chrono::duration_cast<std::chrono::milliseconds>(time).count();

    return serverTime + delta;
}

Timer* Timer::instance = nullptr;