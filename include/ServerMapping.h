#ifndef CPP_WEB_SERVER_REQUESTHANDLER_H
#define CPP_WEB_SERVER_REQUESTHANDLER_H

#include <unordered_map>
#include <memory>
#include <string>
#include <filesystem>
#include <mutex>
#include <utility>

#include <Logger.h>

/// uri -> file path
// TODO implement for function mapping
typedef std::unordered_map<std::string, std::string> uriMethod;

/// Methods in HTTP
enum HTTPMethod{ // std::hash of std::string(method) cropped to unsigned int
    GET = 1158220111,
    PUT = 795930711,
    POST = 2893932544,
    HEAD = 43864722,
    DELETE = 1462665631,
    CONNECT = 2484980613,
    OPTIONS = 1947229628,
    TRACE = 1138122765,
    PATCH = 2564937511
};

class ServerMapping {
public:
    ServerMapping(ServerMapping & _other) = delete;
    void operator=(ServerMapping & _other) = delete;

    static std::shared_ptr<ServerMapping> Instance();

    static void RegisterURI(HTTPMethod method,const std::string & uri, const std::string & path, const std::string & type);

    uriMethod GetURIs(HTTPMethod method);

    std::string GetPath(HTTPMethod method, const std::string & uri);

    std::string GetContentType(const std::string & path);

protected:
    ServerMapping() = default;

    inline static std::shared_ptr<ServerMapping> instance = nullptr;
    inline static std::mutex instanceMtx = std::mutex();

private:

    std::mutex methodsMtx;
    std::unordered_map<HTTPMethod,uriMethod> HTTPMethodsMappings;
    std::mutex pathMtx;
    std::unordered_map<std::string, std::string> PathContentType;

};


#endif //CPP_WEB_SERVER_REQUESTHANDLER_H
