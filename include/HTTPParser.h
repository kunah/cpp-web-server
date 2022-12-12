#ifndef CPP_WEB_SERVER_HTTPPARSER_H
#define CPP_WEB_SERVER_HTTPPARSER_H

#include <memory>
#include <string>
#include <unordered_map>
#include <functional>

#include <Logger.h>

class HTTPParser {
public:
    /// Methods in HTTP
    enum HTTPMethod{ // std::hash of std::string(method) cropped to unsigned int
        GET = 1158220111,
        PUT = 795930711,
        POST = 2893932544,
        HEAD = 43864722,
        DELETE = 1462665631,
        CONNECT = 2484980613,
        OPTIONS = 1947229628,
        TRACE = 1138122765,
        PATCH = 2564937511
    };

    HTTPParser( std::shared_ptr<unsigned char> _buffer, size_t _bufferSize);

    HTTPMethod method;

    std::unordered_map<std::string, std::string> header;

    std::string body;
private:

    void SetMethod(std::string & str);

    std::shared_ptr<unsigned char> buffer;
    size_t bufferSize;
};


#endif //CPP_WEB_SERVER_HTTPPARSER_H
