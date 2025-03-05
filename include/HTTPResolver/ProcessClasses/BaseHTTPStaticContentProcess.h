#ifndef CPP_WEB_SERVER_BASEHTTPSTATICCONTENTPROCESS_H
#define CPP_WEB_SERVER_BASEHTTPSTATICCONTENTPROCESS_H

#include <string>
#include <utility>
#include <fstream>

#include <Logger.h>
#include <HTTPResolver/ProcessClasses/BaseHTTPProcess.h>

namespace ws::http {

    /// Base API class for handling content sending request (images, text files, etc.)
    class BaseHTTPStaticContentProcess : public BaseHTTPProcess {
    public:
        /// \param _filePath path to the file to be send
        /// \param _contentType content of that file
        BaseHTTPStaticContentProcess(std::string _filePath, std::string _contentType);

        virtual ~BaseHTTPStaticContentProcess() = default;

        /// Default method that sends the file as raw bytes without any modifications
        /// \param request Request to handle
        /// \return Answer for the server to send
        HTTPContext Process(HTTPContext &request) override;

    protected:

        std::string filePath;
        std::string contentType;

    private:

    };

} // namespace ws::http

#endif //CPP_WEB_SERVER_BASEHTTPSTATICCONTENTPROCESS_H
