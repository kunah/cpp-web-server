#include "States/HTTPState.h"


HTTPState::HTTPState(HTTPMethod _method) : method(_method) {}

void HTTPState::SetState(HTTPMethod requestMethod) {
    method = requestMethod;
}

HTTPParser HTTPState::HandleRequest(HTTPParser &request) {
    HTTPParser response;
    auto uris = ServerMapping::Instance()->GetURIs(method);

    auto filePath = uris.find(request.uri);

    if(filePath == uris.end()){
        Logger::error("Request URI is not mapped", request.uri);
        throw HTTPError::HTTPNotFound();
    }

    std::fstream file(filePath->second);

    if(!file.is_open()){
        Logger::error("Can't open file", filePath->second);
        throw HTTPError::HTTPNotFound();
    }
    std::string fileInfo, tmp;
    while(file.good()){
        std::getline(file, tmp);
        fileInfo.append(tmp);
    }
    file.close();
    Logger::debug("Content of", filePath->second, fileInfo);

    auto in_time_t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
    response.header["Date"] = ss.str();
    response.header["Content-Length"] = std::to_string(fileInfo.size());
    response.header["Content-Type"] = "text/html";
    response.header["Connection"] = "Closed";
    response.body = fileInfo;
    response.version = "HTTP/1.1 200 OK";

    return response;
}