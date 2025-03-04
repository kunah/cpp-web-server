#ifndef CPP_WEB_SERVER_BASEHTTPPROCESS_H
#define CPP_WEB_SERVER_BASEHTTPPROCESS_H

#include <string>
#include <unordered_map>

#include <Logger.h>
#include <HTTPResolver/HTTPContext.h>
#include <HTTPResolver/Exceptions/ClientError.h>

namespace ws::http {

/// Base API class that is used inside server for handling requests
/// It must be inherited to other Process classes in server
    class BaseHTTPProcess {
    public:
        BaseHTTPProcess() = default;

        virtual ~BaseHTTPProcess() = default;

        /// Main method that is called inside the server
        /// \param request Request to handle
        /// \return Answer for the server to send
        virtual HTTPContext Process(HTTPContext &request) = 0;

    protected:

        std::unordered_map<std::string, std::string> headers;

    private:

    };
}// namespace ws::http

#endif //CPP_WEB_SERVER_BASEHTTPPROCESS_H
