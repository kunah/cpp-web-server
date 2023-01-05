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
        throw HTTPException::HTTPNotFound();
    }

    std::ifstream file(filePath->second, std::ios::binary);

    if(!file.is_open()){
        Logger::error("Can't open file", filePath->second);
        throw HTTPException::HTTPNotFound();
    }
    std::string tmp;
    std::vector<unsigned char> fileInfo(std::istreambuf_iterator<char>(file), {});
    file.close();
    Logger::debug(filePath->second, "File loaded");

    auto in_time_t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::stringstream ssDate;
    ssDate << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
    response.header["Date"] = ssDate.str();
    response.header["Cache-Control"] = "max-age=60";
    response.header["Content-Length"] = std::to_string(fileInfo.size());
    response.header["Content-Type"] = ServerMapping::Instance()->GetContentType(filePath->second);
    response.header["Connection"] = "Closed";
    response.body = fileInfo;
    response.version = "HTTP/1.1 200 OK";

    return response;
}