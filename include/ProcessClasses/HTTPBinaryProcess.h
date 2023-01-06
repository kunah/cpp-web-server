#ifndef CPP_WEB_SERVER_HTTPBINARYPROCESS_H
#define CPP_WEB_SERVER_HTTPBINARYPROCESS_H

#include <utility>
#include <string>

#include <Logger.h>
#include <ProcessClasses/BaseHTTPContentProcess.h>

class HTTPBinaryProcess : public BaseHTTPContentProcess {
public:
    HTTPBinaryProcess(std::string _filePath, std::string _contentType, int _maxAge = 0);
    ~HTTPBinaryProcess() = default;

    HTTPParser Process(HTTPParser & request) override;

protected:

private:

    int maxAge;

};

#endif //CPP_WEB_SERVER_HTTPBINARYPROCESS_H
