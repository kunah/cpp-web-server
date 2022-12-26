#ifndef CPP_WEB_SERVER_HTTPMAPPINGREGISTRAR_H
#define CPP_WEB_SERVER_HTTPMAPPINGREGISTRAR_H

#include <string>

#include <Logger.h>
#include <ServerMapping.h>

class HTTPMappingRegistrar{
public:
    HTTPMappingRegistrar(HTTPMethod method, const std::string & uri, const std::string & path);
};

#define CONCAT_(x,y) x##y
#define CONCAT(x,y) CONCAT_(x,y)

#define REGISTER_URI(method, uri, path) \
static HTTPMappingRegistrar CONCAT(register, __COUNTER__)(method, uri, path);

#endif //CPP_WEB_SERVER_HTTPMAPPINGREGISTRAR_H
