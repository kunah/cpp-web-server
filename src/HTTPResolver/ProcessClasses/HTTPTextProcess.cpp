#include <HTTPResolver/ProcessClasses/HTTPTextProcess.h>

namespace http = ws::http;

http::HTTPTextProcess::HTTPTextProcess(std::string _filePath, std::string _contentType)
        : BaseHTTPStaticContentProcess(std::move(_filePath), std::move(_contentType)) {}

http::HTTPParser http::HTTPTextProcess::Process(HTTPParser &request) {

    HTTPParser response;

    std::ifstream file(filePath);

    if(!file.is_open()){
        Logger::error("Can't open file", filePath);
        throw HTTPException::HTTPNotFound();
    }
    std::vector<unsigned char>fileInfo;
    std::string tmp;
    while(file.good()){
        std::getline(file, tmp);
        fileInfo.insert(fileInfo.end(), tmp.begin(), tmp.end());
    }
    file.close();

    Logger::debug("File loaded", filePath);

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