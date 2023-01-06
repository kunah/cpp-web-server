#ifndef CPP_WEB_SERVER_HTTPTEXTCLASS_H
#define CPP_WEB_SERVER_HTTPTEXTCLASS_H

#include <Logger.h>
#include <ProcessClasses/BaseHTTPContentProcess.h>

/// Class that is used for text files manipulation
class HTTPTextClass final : public BaseHTTPContentProcess {
public:
    HTTPTextClass(std::string  _filePath, std::string  _contentType);
    ~HTTPTextClass() = default;

    /// Manipulates with text files
    /// \param request Requested to handle
    /// \return Answer for the server to send
    HTTPParser Process(HTTPParser & request) override;

};

#endif //CPP_WEB_SERVER_HTTPTEXTCLASS_H
