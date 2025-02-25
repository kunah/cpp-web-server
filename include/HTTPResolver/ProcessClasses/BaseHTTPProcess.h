#ifndef CPP_WEB_SERVER_BASEHTTPPROCESS_H
#define CPP_WEB_SERVER_BASEHTTPPROCESS_H

#include <string>
#include <unordered_map>

#include <Logger.h>
#include <HTTPResolver/HTTPParser.h>
#include <HTTPResolver/Exceptions/ClientError.h>

/// Base API class that is used inside server for handling requests
/// It must be inherited to other Process classes in server
class BaseHTTPProcess{
public:
    BaseHTTPProcess() = default;
    virtual ~BaseHTTPProcess() = default;
    /// Main method that is called inside the server
    /// \param request Request to handle
    /// \return Answer for the server to send
    virtual HTTPParser Process(HTTPParser & request) = 0;

protected:

    std::unordered_map<std::string, std::string> headers;

private:

};

#endif //CPP_WEB_SERVER_BASEHTTPPROCESS_H
