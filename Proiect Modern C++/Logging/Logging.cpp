#include "Logging.h"
#include <chrono>
#include <iomanip>

const char* LogLevelToString(Logger::Level level)
{
	switch (level)
	{
	case Logger::Level::Info:
		return "Info";
	case Logger::Level::Warning:
		return "Warning";
	case Logger::Level::Error:
		return "Error";
	default:
		return "";
	}
}

Logger::Logger(std::ostream& os, Logger::Level minimumLevel) :
	os{ os },
	minimumLevel{ minimumLevel }
{
}

void Logger::log(const char* message, Level level)
{
	if (static_cast<int>(level) < static_cast<int>(minimumLevel))
		return;

	os << "[" << LogLevelToString(level) << "] " << message << std::endl;
}

void Logger::log(const std::string& message, Level level)
{
	auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

#pragma warning(disable: 4996)  //for gmtime

	if (level < minimumLevel)
		return;
	switch (level)
	{
	case Logger::Level::Info:
		os << "[" << std::put_time(gmtime(&now), "%FT%TZ") << "] [INFO] ";
		break;
	case Logger::Level::Warning:
		os << "[" << std::put_time(gmtime(&now), "%FT%TZ") << "] [WARNING] ";
		break;
	case Logger::Level::Error:
		os << "[" << std::put_time(gmtime(&now), "%FT%TZ") << "] [ERROR] ";
		break;
	default:
		break;
	}

#pragma warning(default: 4996)

	os << message << std::endl;
}

void Logger::setMinimumLogLevel(Level level)
{
	this->minimumLevel = level;
}
