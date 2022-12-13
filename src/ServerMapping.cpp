#include "ServerMapping.h"

std::shared_ptr<ServerMapping> ServerMapping::Instance() {
    std::unique_lock<std::mutex> lk(ServerMapping::singletonMtx);
    if(!handler)
        handler = std::shared_ptr<ServerMapping>(new ServerMapping);
    return  handler;
}

void ServerMapping::Add(const std::string &uri, const std::string &path) {
    auto pt = std::filesystem::absolute(path);
    std::unique_lock<std::mutex> lk(mappingMtx);
    if(mappings.find(uri) != mappings.end()){
        Logger::error("Uri",uri,"already mapped");
        throw std::runtime_error("Uri already mapped");
    }
    mappings[uri] = pt;
}

std::filesystem::path ServerMapping::GetMapping(std::string & uri){
    std::unique_lock<std::mutex> lk(mappingMtx);
    auto res = mappings.find(uri);
    if(res == mappings.end()){
        Logger::debug("Mapping for Uri", uri, "doesn't exist");
        throw std::runtime_error("Mapping doesn't exist");
    }
    return res->second;
}