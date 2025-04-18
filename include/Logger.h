#ifndef CPP_WEB_SERVER_LOGGER_H
#define CPP_WEB_SERVER_LOGGER_H

#include <mutex>
#include <chrono>
#include <memory>
#include <cerrno>
#include <iomanip>
#include <sstream>
#include <iostream>

#ifndef LOG_LEVEL
    #warning "LOG_LEVEL macro is not defined, setting default values"
    #define LOG_LEVEL Logger::Level::OFF
#endif

namespace ws {


/// Singleton class that handles output for the application
    class Logger {
    public:

        /// Supported debug levels
        enum Level {
            OFF = 0,
            ERROR,
            WARN,
            INFO,
            DEBUG,
            TEST,
            UlTRA
        };

        Logger(Logger &other) = delete;

        void operator=(Logger &other) = delete;

        /// API for printing messages in ERROR level
        template<class ... Args>
        inline static void error(Args ... args) {
            Logger::Instance()->PrintMultipleLog(Logger::Level::ERROR, "[ERROR]", args...);
        }

        /// API for printing messages in WARN level
        template<class ... Args>
        inline static void warn(Args ... args) {
            Logger::Instance()->PrintMultipleLog(Logger::Level::WARN, "[WARN]", args...);
        }

        /// API for printing messages in INFO level
        template<class ... Args>
        inline static void info(Args ... args) {
            Logger::Instance()->PrintMultipleLog(Logger::Level::INFO, "[INFO]", args...);
        }

        /// API for printing messages in DEBUG level
        template<class ... Args>
        inline static void debug(Args ... args) {
            Logger::Instance()->PrintMultipleLog(Logger::Level::DEBUG, "[DEBUG]", args...);
        }

        /// API for printing messages in ULTRA level
        template<class ... Args>
        inline static void ultra(Args ... args) {
            Logger::Instance()->PrintMultipleLog(Logger::Level::UlTRA, "[ULTRA]", args...);
        }

        /// \return the content of the std::ostringstream as a string
        static std::string GetSS();

        /// Clear the std::ostringstream
        static void ClearSS();


    protected:

        /// Protected constructor to preserve singleton architecture
        /// \param _level maximum level of printable messages
        Logger(Logger::Level _level = Logger::Level::INFO);

        /// Gets instance of the current logger
        /// \warning NOT accessible from outside the class
        static std::shared_ptr<Logger> Instance();

        inline static std::shared_ptr<Logger> loggerInstance = nullptr;

    private:

        /// Print arguments to the output stream
        template<class ... Args>
        inline void PrintMultipleLog(Logger::Level msgLevel, Args ... args) {
            if (level < msgLevel)
                return;
            mtx.lock();
            PrintCurrentTime();
            ((GetStream() << " " << args), ...);
            GetStream() << std::endl;
            mtx.unlock();
        }

        /// \return the output stream that should be used in this logger
        std::ostream &GetStream();

        /// Gets current time and print it to the output stream
        std::ostream &PrintCurrentTime();

        std::mutex mtx;

        Logger::Level level;

        std::ostream &outStream;
        std::ostringstream oss;
    };

} // namespace ws

#endif //CPP_WEB_SERVER_LOGGER_H
