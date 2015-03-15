#include "MT2ConnectorPrivatePCH.h"
#include "Logger.h"



DEFINE_LOG_CATEGORY(MT2Log);
Logger::Logger() {


    debugMode = false;
}

Logger::~Logger() {
}


void Logger::debug(std::string message, ...) {
    if(!isDebugMode())
        return;

    char buffer[4096];

    va_list args;
    va_start(args, message);
    vsnprintf(buffer, sizeof(buffer), message.c_str(), args);
    va_end(args);

    log("DEBUG", buffer);
}

void Logger::info(std::string message, ...) {
    char buffer[4096];

    va_list args;
    va_start(args, message);
    vsnprintf(buffer, sizeof(buffer), message.c_str(), args);
    va_end(args);

    log("INFO", buffer);
}

void Logger::warn(std::string message, ...) {
    char buffer[4096];

    va_list args;
    va_start(args, message);
    vsnprintf(buffer, sizeof(buffer), message.c_str(), args);
    va_end(args);

    log("WARN", buffer);
}

void Logger::fatal(std::string message, ...) {
    char buffer[4096];

    va_list args;
    va_start(args, message);
    vsnprintf(buffer, sizeof(buffer), message.c_str(), args);
    va_end(args);

    log("FATAL", buffer);
}

void Logger::log(std::string level, std::string message) {
	FString msg = FString(message.c_str());
	UE_LOG(MT2Log, Warning, TEXT("%s"), *msg);
    /*std::cout << boost::posix_time::microsec_clock::local_time();
    std::cout << std::setw(6) << level.c_str() << " ";
    std::cout << message.c_str() << std::endl;*/
}

Logger *Logger::getInstance() {
    if(instance == nullptr) {
        instance = new Logger();
    }

    return instance;
}

Logger* Logger::instance = nullptr;
