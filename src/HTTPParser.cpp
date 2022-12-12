#include <HTTPParser.h>

HTTPParser::HTTPParser(std::shared_ptr<unsigned char> _buffer, size_t _bufferSize) : buffer(_buffer), bufferSize(_bufferSize) {

    size_t index = 0;
    std::string strMethod, uri, mode;
    while(index < bufferSize){
        if(isspace(buffer.get()[index]))
            break;
        strMethod.push_back(buffer.get()[index]);
        ++index;
    }
    ++index;
    SetMethod(strMethod);
    while(index < bufferSize){
        if(isspace(buffer.get()[index]))
            break;
        uri.push_back(buffer.get()[index]);
        ++index;
    }
    ++index;
    while(index < bufferSize){
        if(isspace(buffer.get()[index]))
            break;
        mode.push_back(buffer.get()[index]);
        ++index;
    }

    Logger::debug(strMethod, uri, mode);

}

void HTTPParser::SetMethod(std::string &str) {
    auto hash = (unsigned int)std::hash<std::string>()(str);
    switch (hash) {
        case HTTPMethod::GET:
            method = HTTPMethod::GET;
            break;
        case HTTPMethod::PUT:
            method = HTTPMethod::PUT;
            break;
        case HTTPMethod::POST:
            method = HTTPMethod::POST;
            break;
        case HTTPMethod::HEAD:
            method = HTTPMethod::HEAD;
            break;
        case HTTPMethod::DELETE:
            method = HTTPMethod::DELETE;
            break;
        case HTTPMethod::CONNECT:
            method = HTTPMethod::CONNECT;
            break;
        case HTTPMethod::OPTIONS:
            method = HTTPMethod::OPTIONS;
            break;
        case HTTPMethod::TRACE:
            method = HTTPMethod::TRACE;
            break;
        case HTTPMethod::PATCH:
            method = HTTPMethod::PATCH;
            break;
        default:
            Logger::debug("Short message");
            throw std::runtime_error("Short message");
    }
}