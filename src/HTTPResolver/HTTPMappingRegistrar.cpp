#include <HTTPResolver/HTTPMappingRegistrar.h>

namespace http = ws::http;

http::HTTPMappingRegistrar::HTTPMappingRegistrar(HTTPMethod method, const std::string &uri, ws::internal::functionProcess fnc) {
    Logger::debug("Registering uri:", uri);
    ws::internal::ServerMapping::Instance()->RegisterURI(method, uri, std::move(fnc));
}