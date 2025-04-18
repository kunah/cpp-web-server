#ifndef CPP_WEB_SERVER_HTTPFILEPROCESS_H
#define CPP_WEB_SERVER_HTTPFILEPROCESS_H

#include <string>
#include <utility>

#include <Logger.h>
#include <HTTPResolver/ProcessClasses/BaseHTTPStaticContentProcess.h>

namespace ws::http {


    /// Class for sending binary data
    class HTTPFileProcess : public BaseHTTPStaticContentProcess {
    public:
        /// Default constructor
        /// \param _filePath Path to the binary file
        /// \param _contentType Type of the file
        /// \param _maxAge Max age of the file for caching
        HTTPFileProcess(std::string _filePath, std::string _contentType, uint32_t _maxAge = 0);

        ~HTTPFileProcess() = default;

        /// Manipulates with text files
        /// \param request Requested to handle
        /// \return Answer for the server to send
        HTTPContext Process(HTTPContext &request) override;

    protected:

    private:

        uint32_t maxAge;

    };

} // namespace ws::http

#endif //CPP_WEB_SERVER_HTTPFILEPROCESS_H
