#ifndef CPP_WEB_SERVER_HTTPMAPPINGREGISTRAR_H
#define CPP_WEB_SERVER_HTTPMAPPINGREGISTRAR_H

#include <string>

#include <Logger.h>
#include <ServerMapping.h>

/// Base class that registers new uri
class HTTPMappingRegistrar{
public:
    /// Register uri for given method to the ServerMapping
    /// Registration process begins with the object being created
    /// \param method HTTP method that will be assigned to this uri
    /// \param uri uri starting from root
    /// \param path path to file to send back
    /// \param type type of file to be added to HTTP response Content-Type header section
    HTTPMappingRegistrar(HTTPMethod method, const std::string & uri, const std::string & path, const std::string & type);
};

#define CONCAT_(x,y) x##y
#define CONCAT(x,y) CONCAT_(x,y)

/// Macro to add new uri mapping
#define REGISTER_URI(method, uri, path, type) \
static HTTPMappingRegistrar CONCAT(register, __COUNTER__)(method, uri, path, type);

#endif //CPP_WEB_SERVER_HTTPMAPPINGREGISTRAR_H
