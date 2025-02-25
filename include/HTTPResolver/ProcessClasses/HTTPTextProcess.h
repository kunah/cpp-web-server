#ifndef CPP_WEB_SERVER_HTTPTEXTPROCESS_H
#define CPP_WEB_SERVER_HTTPTEXTPROCESS_H

#include <string>
#include <fstream>

#include <Logger.h>
#include <ServerMapping.h>
#include <HTTPResolver/Exceptions/ClientError.h>
#include <HTTPResolver/ProcessClasses/BaseHTTPStaticContentProcess.h>

/// Class that is used for text files manipulation
class HTTPTextProcess final : public BaseHTTPStaticContentProcess {
public:
    HTTPTextProcess(std::string  _filePath, std::string  _contentType);
    ~HTTPTextProcess() = default;

    /// Manipulates with text files
    /// \param request Requested to handle
    /// \return Answer for the server to send
    HTTPParser Process(HTTPParser & request) override;

};

#endif //CPP_WEB_SERVER_HTTPTEXTPROCESS_H
