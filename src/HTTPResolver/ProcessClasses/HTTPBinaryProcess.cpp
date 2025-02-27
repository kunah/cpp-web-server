#include <HTTPResolver/ProcessClasses/HTTPBinaryProcess.h>

namespace http = ws::http;
namespace HTTPException = ws::HTTPException;

http::HTTPBinaryProcess::HTTPBinaryProcess(std::string _filePath, std::string _contentType, uint32_t _maxAge)
        : BaseHTTPStaticContentProcess(std::move(_filePath), std::move(_contentType)), maxAge(_maxAge) {}

http::HTTPParser http::HTTPBinaryProcess::Process(http::HTTPParser &request) {

    http::HTTPParser response;

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
    response.header["Cache-Control"] = "max-age=" + std::to_string(maxAge);
    response.header["Content-Length"] = std::to_string(fileInfo.size());
    response.header["Content-Type"] = contentType;
    response.header["Connection"] = "Closed";
    response.body = fileInfo;
    response.version = "HTTP/1.1 200 OK";

    return response;

}