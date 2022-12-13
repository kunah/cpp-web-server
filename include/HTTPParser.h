#ifndef CPP_WEB_SERVER_HTTPPARSER_H
#define CPP_WEB_SERVER_HTTPPARSER_H

#include <memory>
#include <string>
#include <unordered_map>
#include <functional>
#include <sstream>

#include <Logger.h>
#include <ServerMapping.h>

class HTTPParser {
public:


    HTTPParser();
    HTTPParser( std::shared_ptr<unsigned char> _buffer, size_t _bufferSize);
    void operator=( const HTTPParser & _other);

    std::string ToString();

    HTTPMethod method;

    std::unordered_map<std::string, std::string> header;

    std::string body;
    std::string uri;
    std::string version;
private:

    void SetMethod(std::string & str);

    void ParseHeader();
    std::string GetLine();

    std::shared_ptr<unsigned char> buffer;
    size_t bufferSize;
    size_t index;
};


#endif //CPP_WEB_SERVER_HTTPPARSER_H
