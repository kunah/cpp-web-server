#include <HTTPResolver/HTTPParser.h>
#include <HTTPResolver/Exceptions/ClientError.h> // added to avoid cyclic includes

using namespace ws::http;

HTTPParser::HTTPParser() : method(HTTPMethod::GET), bufferSize(0), index(0) {}

HTTPParser::HTTPParser(std::vector<unsigned char> _buffer, size_t _bufferSize) : buffer(std::move(_buffer)), bufferSize(_bufferSize) {

    index = 0;
    std::string strMethod;
    while(index < bufferSize){
        if(isspace(buffer[index]))
            break;
        strMethod.push_back(buffer[index]);
        ++index;
    }
    ++index;
    SetMethod(strMethod);

    std::string uri;
    while(index < bufferSize){
        if(isspace(buffer[index]))
            break;
        uri.push_back(buffer[index]);
        ++index;
    }
    url = uri;
    ++index;
    while(index < bufferSize){
        if(isspace(buffer[index]))
            break;
        version.push_back(buffer[index]);
        ++index;
    }
    while(isspace(buffer[index]))
        ++index;

    Logger::debug(strMethod, uri, version);

    ParseHeader();

    while(index < bufferSize){
        auto tmp = GetLine();
        body.insert(body.end(), tmp.begin(), tmp.end());
    }
    Logger::debug("Request parsed");
}

HTTPParser & HTTPParser::operator=(const HTTPParser &_other) {
    if(&_other == this)
        return *this;
    this->index = _other.index;
    this->buffer = _other.buffer;
    this->method = _other.method;
    this->bufferSize = _other.bufferSize;
    this->version = _other.version;
    this->body = _other.body;
    this->header = _other.header;
    this->url = _other.url;

    return *this;
}

std::vector<unsigned char> HTTPParser::ToData()  {
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

    if(str == "GET")
        method = HTTPMethod::GET;
    else if(str == "PUT")
        method = HTTPMethod::PUT;
    else if(str == "POST")
        method = HTTPMethod::POST;
    else if(str == "HEAD")
        method = HTTPMethod::HEAD;
    else if(str == "DELETE")
        method = HTTPMethod::DELETE;
    else if(str == "CONNECT")
        method = HTTPMethod::CONNECT;
    else if(str == "OPTIONS")
        method = HTTPMethod::OPTIONS;
    else if(str == "TRACE")
        method = HTTPMethod::TRACE;
    else if(str == "PATCH")
        method = HTTPMethod::PATCH;
    else{
        Logger::debug("Unknown method");
        throw HTTPException::HTTPBadRequest("Unknown method");
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
            throw HTTPException::HTTPBadRequest();
        }
        std::string headerName(line.begin(), line.begin() + res), headerValue(line.begin() + res + 2, line.end());
        Logger::ultra(headerName, headerValue);
        header[headerName] = headerValue;
    }

}

std::string HTTPParser::GetLine() {
    std::string ret;
    while(index < bufferSize){
        if(buffer[index] == '\n'){
            ++index;
            break;
        }
        if(buffer[index] == '\r'){
            ++index;
            continue;
        }
        ret.push_back(buffer[index]);
        ++index;
    }
    return ret;
}