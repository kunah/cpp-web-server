#include <HTTPMappingRegistrar.h>

HTTPMappingRegistrar::HTTPMappingRegistrar(HTTPMethod method, const std::string &uri, functionProcess fnc) {
    Logger::debug("Registering uri:", uri);
    ServerMapping::Instance()->RegisterURI(method, uri, std::move(fnc));
}