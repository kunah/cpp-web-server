#include "Logger.h"

Logger::Logger(Logger::Level _level) : level(_level), outStream(std::cout){}

std::shared_ptr<Logger> Logger::Instance() {
    if(!loggerInstance)
        loggerInstance = std::shared_ptr<Logger>(new Logger(LOG_LEVEL));
    return loggerInstance;
}

std::ostream & Logger::PrintCurrentTime() {
    auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    auto time = std::gmtime(&now);
    outStream << '[' << std::setw(2) << std::setfill('0') <<  time->tm_hour << ':';
    outStream << std::setw(2) << std::setfill('0') <<  time->tm_min << ':';
    outStream << std::setw(2) << std::setfill('0') <<  time->tm_sec << ']';
    return outStream;
}