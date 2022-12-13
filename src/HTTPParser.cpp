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

    while(index < bufferSize)
        body.append(GetLine());
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

std::string HTTPParser::ToString()  {
    std::stringstream ss;
    ss << version << "\r\n";
    for(auto [head, info] : header){
        ss << head << ": " << info << "\r\n";
    }
    ss << "\r\n";
    ss << body << "\r\n";
    return ss.str();
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
        Logger::info(std::string(line.begin(), line.begin() + res), std::string(line.begin() + res + 2, line.end()));
        header[{line.begin(), line.begin() + res}] = {line.begin() + res + 2, line.end()};
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