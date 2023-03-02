#include <Logger.h>

Logger::Logger(Logger::Level _level) : level(_level), outStream(std::cout){}

std::shared_ptr<Logger> Logger::Instance() {
    if(!loggerInstance)
        loggerInstance = std::shared_ptr<Logger>(new Logger(LOG_LEVEL));
    return loggerInstance;
}

std::ostream & Logger::PrintCurrentTime() {
    auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    return GetStream() << std::put_time(std::localtime(&now), "[%Y-%m-%d %X]");
}

std::string Logger::GetSS() {
    auto instance = Logger::Instance();
    if(instance->level != Logger::TEST)
        return "";
    return instance->oss.str();
}

void Logger::ClearSS() {
    auto instance = Logger::Instance();
    instance->oss.clear();
}

std::ostream & Logger::GetStream(){
    if(level == Logger::TEST)
        return oss;
    return outStream;
}