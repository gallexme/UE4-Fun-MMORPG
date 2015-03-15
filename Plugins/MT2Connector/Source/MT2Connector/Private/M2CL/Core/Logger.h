

#pragma once
#include <string>
#include <stdarg.h>
DECLARE_LOG_CATEGORY_EXTERN(MT2Log, Log, All);

class Logger {
public:
	Logger();
	~Logger();

	//void debug(std::string message);
	void debug(std::string message, ...);
	void info(std::string message, ...);
	void warn(std::string message, ...);
	void fatal(std::string message, ...);

	static Logger* getInstance();

	bool isDebugMode() const {
		return debugMode;
	}

	void setDebugMode(bool debugMode) {
		Logger::debugMode = debugMode;
	}

private:
	void log(std::string level, std::string message);
private:
	static Logger* instance;
	bool debugMode;
};
