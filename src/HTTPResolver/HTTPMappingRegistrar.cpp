#include <HTTPResolver/HTTPMappingRegistrar.h>

using namespace ws::http;

HTTPMappingRegistrar::HTTPMappingRegistrar(HTTPMethod method, const std::string &uri, _mapping::functionProcess fnc) {
    Logger::debug("Registering uri:", uri);
    _mapping::ServerMapping::Instance()->RegisterURI(method, uri, std::move(fnc));
}