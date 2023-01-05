#include <HTTPParser.h>

HTTPParser::HTTPParser() : method(HTTPMethod::GET), buffer(nullptr), bufferSize(0), index(0) {}

HTTPParser::HTTPParser(std::shared_ptr<unsigned char> _buffer, size_t _bufferSize) : buffer(std::move(_buffer)), bufferSize(_bufferSize) {

    index = 0;
    std::string strMethod;
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
        version.push_back(buffer.get()[index]);
        ++index;
    }
    while(isspace(buffer.get()[index]))
        ++index;

    Logger::debug(strMethod, uri, version);

    ParseHeader();

    while(index < bufferSize){
        auto tmp = GetLine();
        body.insert(body.end(), tmp.begin(), tmp.end());
    }
    Logger::debug("Request parsed");
}

void HTTPParser::operator=(const HTTPParser &_other) {
    this->index = _other.index;
    this->buffer = _other.buffer;
    this->method = _other.method;
    this->bufferSize = _other.bufferSize;
    this->version = _other.version;
    this->body = _other.body;
    this->header = _other.header;
    this->uri = _other.uri;
}

std::vector<unsigned char> HTTPParser::ToData()  {
    std::stringstream ss;
    std::vector<unsigned char> buffer;
    buffer.insert(buffer.end(), version.begin(), version.end());
    buffer.insert(buffer.end(), {'\r','\n'});
    for(auto [head, info] : header){
        buffer.insert(buffer.end(), head.begin(), head.end());
        buffer.insert(buffer.end(), {':', ' '});
        buffer.insert(buffer.end(), info.begin(), info.end());
        buffer.insert(buffer.end(), {'\r','\n'});
    }
    buffer.insert(buffer.end(), {'\r','\n'});
    buffer.insert(buffer.end(), body.begin(), body.end());
    buffer.insert(buffer.end(), {'\r','\n'});
    return buffer;
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

void HTTPParser::ParseHeader() {

    while(true){
        auto line = GetLine();
        if(line.empty())
            return;

        auto res = line.find(':');
        if(res == std::string::npos){
            Logger::debug("Not a header line");
            throw std::runtime_error("Bad header");
        }
        std::string headerName(line.begin(), line.begin() + res), headerValue(line.begin() + res + 2, line.end());
        Logger::ultra(headerName, headerValue);
        header[headerName] = headerValue;
    }

}

std::string HTTPParser::GetLine() {
    std::string ret;
    while(index < bufferSize){
        if(buffer.get()[index] == '\n'){
            ++index;
            break;
        }
        if(buffer.get()[index] == '\r'){
            ++index;
            continue;
        }
        ret.push_back(buffer.get()[index]);
        ++index;
    }
    return ret;
}