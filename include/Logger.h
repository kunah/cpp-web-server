#ifndef CPP_WEB_SERVER_LOGGER_H
#define CPP_WEB_SERVER_LOGGER_H

#include <iostream>
#include <chrono>
#include <iomanip>
#include <mutex>

#define LOG_LEVEL Logger::Level::DEBUG

class Logger {
public:

    enum Level{
        OFF = 0,
        ERROR,
        WARN,
        INFO,
        DEBUG
    };

    Logger(Logger & other) = delete;
    void operator=(Logger & other) = delete;

    static void error(const std::string & msg);
    static void warn(const std::string & msg);
    static void info(const std::string & msg);
    static void debug(const std::string & msg);


protected:

    Logger(Logger::Level _level);

    static std::shared_ptr<Logger> Instance();

    inline static std::shared_ptr<Logger> loggerInstance = nullptr;

private:

    void PrintLog(Logger::Level msgLevel, const std::string & msg);

    std::ostream & PrintCurrentTime();

    std::mutex mtx;

    Logger::Level level;

    std::ostream & outStream;
};

#endif //CPP_WEB_SERVER_LOGGER_H
