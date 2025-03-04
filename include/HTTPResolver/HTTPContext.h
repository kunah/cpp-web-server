#ifndef CPP_WEB_SERVER_HTTPCONTEXT_H
#define CPP_WEB_SERVER_HTTPCONTEXT_H

#include <memory>
#include <string>
#include <vector>
#include <sstream>
#include <functional>
#include <unordered_map>

#include <Logger.h>
#include <URL/URL.h>
#include <HTTPResolver/HTTPMethod.h>

namespace ws::http {

/// Class that parses incoming HTTP request
    class HTTPContext {
    public:


        /// Creates empty object
        HTTPContext();

        /// Creates object with parsed HTTP data from buffer
        HTTPContext(std::vector<unsigned char> _buffer, size_t _bufferSize);

        HTTPContext &operator=(const HTTPContext &_other);

        /// Prepares HTTP response
        std::vector<unsigned char> ToData();

        HTTPMethod method;

        std::unordered_map<std::string, std::string> header;

        std::vector<unsigned char> body;
        url::URL url;
        std::string version;
    private:

        void SetMethod(std::string &str);

        void ParseHeader();

        std::string GetLine();

        std::vector<unsigned char> buffer;
        size_t bufferSize;
        size_t index;
    };

} // namespace ws::http

#endif //CPP_WEB_SERVER_HTTPCONTEXT_H
