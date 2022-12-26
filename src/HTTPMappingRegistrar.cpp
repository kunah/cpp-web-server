#include <HTTPMappingRegistrar.h>

HTTPMappingRegistrar::HTTPMappingRegistrar(HTTPMethod method, const std::string &uri, const std::string &path) {
    Logger::debug("Registering uri:", uri);
    ServerMapping::Instance()->RegisterURI(method, uri, path);
}