#include <Logger.h>

ws::Logger::Logger(ws::Logger::Level _level) : level(_level), outStream(std::cout){}

std::shared_ptr<ws::Logger> ws::Logger::Instance() {
    if(!loggerInstance)
        loggerInstance = std::shared_ptr<Logger>(new Logger(LOG_LEVEL));
    return loggerInstance;
}

std::ostream & ws::Logger::PrintCurrentTime() {
    auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    return GetStream() << std::put_time(std::localtime(&now), "[%Y-%m-%d %X]");
}

std::string ws::Logger::GetSS() {
    auto instance = Logger::Instance();
    if(instance->level != Logger::TEST)
        return "";
    return instance->oss.str();
}

void ws::Logger::ClearSS() {
    auto instance = Logger::Instance();
    instance->oss.str("");
}

std::ostream & ws::Logger::GetStream(){
    if(level == Logger::TEST)
        return oss;
    return outStream;
}