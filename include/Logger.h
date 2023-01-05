#ifndef CPP_WEB_SERVER_LOGGER_H
#define CPP_WEB_SERVER_LOGGER_H

#include <iostream>
#include <chrono>
#include <iomanip>
#include <mutex>
#include <cerrno>

#define LOG_LEVEL Logger::Level::INFO

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

    template<class ... Args>
    inline static void error(Args ... args) {
        Logger::Instance()->PrintMultipleLog(Logger::Level::ERROR, "[ERROR]", args...);
    }
    template<class ... Args>
    inline static void warn(Args ... args) {
        Logger::Instance()->PrintMultipleLog(Logger::Level::WARN, "[WARN]", args...);
    }
    template<class ... Args>
    inline static void info(Args ... args) {
        Logger::Instance()->PrintMultipleLog(Logger::Level::INFO, "[INFO]", args...);
    }
    template<class ... Args>
    inline static void debug(Args ... args) {
        Logger::Instance()->PrintMultipleLog(Logger::Level::DEBUG, "[DEBUG]", args...);
    }


protected:

    Logger(Logger::Level _level = Logger::Level::INFO);

    static std::shared_ptr<Logger> Instance();

    inline static std::shared_ptr<Logger> loggerInstance = nullptr;

private:

    template<class ... Args>
    inline void PrintMultipleLog(Logger::Level msgLevel, Args ... args) {
        if(level < msgLevel)
            return;
        mtx.lock();
        PrintCurrentTime();
        ((outStream << " " << args) , ...);
        outStream << std::endl;
        mtx.unlock();
    }

    std::ostream & PrintCurrentTime();

    std::mutex mtx;

    Logger::Level level;

    std::ostream & outStream;
};

#endif //CPP_WEB_SERVER_LOGGER_H
