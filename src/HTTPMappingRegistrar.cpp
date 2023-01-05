#include <HTTPMappingRegistrar.h>

HTTPMappingRegistrar::HTTPMappingRegistrar(HTTPMethod method, const std::string &uri, const std::string &path, const std::string &type) {
    Logger::debug("Registering uri:", uri);
    ServerMapping::Instance()->RegisterURI(method, uri, path, type);
}