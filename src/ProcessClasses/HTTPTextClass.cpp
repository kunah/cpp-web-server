#include <ProcessClasses/HTTPTextClass.h>

HTTPTextClass::HTTPTextClass(std::string _filePath, std::string _contentType)
        : BaseHTTPContentProcess(std::move(_filePath), std::move(_contentType)) {}

HTTPParser HTTPTextClass::Process(HTTPParser &request) {
    // TODO: implement text class manipulation
    return {};
}