#include <Exceptions/HTTPExceptionBase.h>




HTTPException::HTTPExceptionBase::HTTPExceptionBase( ErrorCode _code, std::string _msg, bool _webSite, std::string  _site)
: code(_code), webSite(_webSite), site(std::move(_site)), msg(std::move(_msg)) {}

HTTPParser HTTPException::HTTPExceptionBase::Response() {

    HTTPParser response;

    auto in_time_t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");

    response.header["Date"] = ss.str();
    if (webSite) {

        std::fstream file(site);

        if (!file.is_open()) {
            Logger::error("Can't open file", site);
            throw std::runtime_error("Can't open file for given mapping");
        }
        std::vector<unsigned char> fileInfo(std::istreambuf_iterator<char>(file), {});
        file.close();

        response.header["Content-Length"] = std::to_string(fileInfo.size());

        response.header["Content-Type"] = "text/html";
        response.body = fileInfo;
    }
    response.header["Connection"] = "Closed";
    ss.str("");
    ss << "HTTP/1.1 " << code << " " << msg;
    response.version = ss.str();

    return response;
}