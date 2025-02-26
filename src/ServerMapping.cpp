#include <ServerMapping.h>

namespace internal = ws::internal;

std::shared_ptr<internal::ServerMapping> internal::ServerMapping::Instance() {
    std::unique_lock<std::mutex> lk(instanceMtx);
    if(!instance)
        instance = std::shared_ptr<ServerMapping>(new ServerMapping);
    return  instance;
}


void internal::ServerMapping::RegisterURI(http::HTTPMethod method, const std::string &uri, functionProcess fnc) {
//    auto pt = std::filesystem::absolute(path);
    ServerMapping::Instance(); // make sure to init Server Mapping
    std::unique_lock<std::mutex> lkM(instance->methodsMtx);
//    auto res = std::find_if(instance->HTTPMethodsMappings[method].begin(), instance->HTTPMethodsMappings[method].end(),
//                            [&uri](std::pair<PatternURL, functionProcess>& posUri){return posUri.first == uri;});
//    if(res != instance->HTTPMethodsMappings[method].end()){
//        Logger::error("Trying to register uri for the same method");
//        throw std::runtime_error("Trying to register uri for the same method");
//    }

    instance->HTTPMethodsMappings[method].RegisterURL(uri, std::move(fnc));
}

const ws::url::URLMapper & internal::ServerMapping::GetURIs(http::HTTPMethod method) {
    std::unique_lock<std::mutex> lk(methodsMtx);
    return HTTPMethodsMappings[method];
}

internal::functionProcess internal::ServerMapping::GetProcess(ws::http::HTTPMethod method, ws::url::URL &uri) {
    std::unique_lock<std::mutex> lk(methodsMtx);
//    auto res = std::find_if(HTTPMethodsMappings[method].begin(), HTTPMethodsMappings[method].end(),
//                            [&uri](std::pair<PatternURL, functionProcess>& posUri){return posUri.first == uri;});
//    if(res == HTTPMethodsMappings[method].end()){
//        Logger::error("Uri is not mapped for this method", uri);
//        throw std::runtime_error("Uri is not mapped for this method");
//    }

    auto res = HTTPMethodsMappings[method].FindURL(uri);

    return res.first;
}