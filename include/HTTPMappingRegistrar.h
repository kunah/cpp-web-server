#ifndef CPP_WEB_SERVER_HTTPMAPPINGREGISTRAR_H
#define CPP_WEB_SERVER_HTTPMAPPINGREGISTRAR_H

#include <string>
#include <memory>

#include <Logger.h>
#include <ServerMapping.h>
#include <ProcessClasses/BaseHTTPContentProcess.h>

/// Base class that registers new uri
class HTTPMappingRegistrar{
public:
    /// Register uri for given method to the ServerMapping
    /// Registration process begins with the object being created
    /// \param method HTTP method that will be assigned to this uri
    /// \param uri uri starting from root
    /// \param fnc function that creates object that handles incoming request
    HTTPMappingRegistrar(HTTPMethod method, const std::string & uri, functionProcess fnc);
};

#ifndef CONCAT
    #define CONCAT_(x,y) x##y
    #define CONCAT(x,y) CONCAT_(x,y)
#endif

/// Macro to add new uri mapping
#define REGISTER_URI(method, uri, obj, args...) \
static HTTPMappingRegistrar CONCAT(register, __COUNTER__)(method, uri, [](){return std::make_shared<obj>(args);});

#define REGISTER_GET_URI(uri, path, args...) REGISTER_URI(HTTPMethod::GET, uri, path, args)
#endif //CPP_WEB_SERVER_HTTPMAPPINGREGISTRAR_H
