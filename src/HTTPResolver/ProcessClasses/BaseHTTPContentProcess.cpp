#include <HTTPResolver/ProcessClasses/BaseHTTPStaticContentProcess.h>

using namespace ws::http;

BaseHTTPStaticContentProcess::BaseHTTPStaticContentProcess(std::string _filePath, std::string _contentType)
        : filePath(std::move(_filePath)), contentType(std::move(_contentType)) {}

HTTPParser BaseHTTPStaticContentProcess::Process(HTTPParser &request) {

    HTTPParser response;

    std::ifstream file(filePath, std::ios::binary);

    if(!file.is_open()){
        Logger::error("Can't open file", filePath);
        throw HTTPException::HTTPNotFound();
    }
    std::string tmp;
    std::vector<unsigned char> fileInfo(std::istreambuf_iterator<char>(file), {});
    file.close();
    Logger::debug(filePath, "File loaded");

    auto in_time_t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::stringstream ssDate;
    ssDate << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
    response.header["Date"] = ssDate.str();
    response.header["Cache-Control"] = "max-age=0";
    response.header["Content-Length"] = std::to_string(fileInfo.size());
    response.header["Content-Type"] = contentType;
    response.header["Connection"] = "Closed";
    response.body = fileInfo;
    response.version = "HTTP/1.1 200 OK";

    return response;

}