#ifndef CPP_WEB_SERVER_HTTPPARSER_H
#define CPP_WEB_SERVER_HTTPPARSER_H

#include <memory>
#include <string>
#include <unordered_map>
#include <functional>
#include <sstream>
#include <vector>

#include <Logger.h>
#include <HTTPMethod.h>

/// Class that parses incoming HTTP request
class HTTPParser {
public:


    /// Creates empty object
    HTTPParser();
    /// Creates object with parsed HTTP data from buffer
    HTTPParser( std::vector<unsigned char> _buffer, size_t _bufferSize);
    HTTPParser & operator=( const HTTPParser & _other);

    /// Prepares HTTP response
    std::vector<unsigned char> ToData();

    HTTPMethod method;

    std::unordered_map<std::string, std::string> header;

    std::vector<unsigned char> body;
    std::string uri;
    std::string version;
private:

    void SetMethod(std::string & str);

    void ParseHeader();
    std::string GetLine();

    std::vector<unsigned char> buffer;
    size_t bufferSize;
    size_t index;
};


#endif //CPP_WEB_SERVER_HTTPPARSER_H
