#include "ServerMapping.h"

std::shared_ptr<ServerMapping> ServerMapping::Instance() {
    std::unique_lock<std::mutex> lk(instanceMtx);
    if(!instance)
        instance = std::shared_ptr<ServerMapping>(new ServerMapping);
    return  instance;
}


void ServerMapping::RegisterURI(HTTPMethod method, const std::string &uri, const std::string &path) {
//    auto pt = std::filesystem::absolute(path);
    ServerMapping::Instance(); // make sure to init Server Mapping
    std::unique_lock<std::mutex> lk(instance->methodsMtx);
    auto res = instance->HTTPMethodsMappings[method].find(uri);
    if(res != instance->HTTPMethodsMappings[method].end()){
        Logger::error("Trying to register uri for the same method");
        throw std::runtime_error("Trying to register uri for the same method");
    }

    instance->HTTPMethodsMappings[method][uri] = path;
}

uriMethod ServerMapping::GetURIs(HTTPMethod method) {
    std::unique_lock<std::mutex> lk(methodsMtx);
    return HTTPMethodsMappings[method];
}

std::string ServerMapping::GetPath(HTTPMethod method, const std::string &uri) {
    std::unique_lock<std::mutex> lk(methodsMtx);
    auto res = HTTPMethodsMappings[method].find(uri);
    if(res == HTTPMethodsMappings[method].end()){
        Logger::error("Uri is not mapped for this method", uri);
        throw std::runtime_error("Uri is not mapped for this method");
    }
    return res->second;
}