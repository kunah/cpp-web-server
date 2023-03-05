#include <ServerMapping.h>

std::shared_ptr<ServerMapping> ServerMapping::Instance() {
    std::unique_lock<std::mutex> lk(instanceMtx);
    if(!instance)
        instance = std::shared_ptr<ServerMapping>(new ServerMapping);
    return  instance;
}


void ServerMapping::RegisterURI(HTTPMethod method, const std::string &uri, functionProcess fnc) {
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

const URLMapper & ServerMapping::GetURIs(HTTPMethod method) {
    std::unique_lock<std::mutex> lk(methodsMtx);
    return HTTPMethodsMappings[method];
}

functionProcess ServerMapping::GetProcess(HTTPMethod method, const std::string &uri) {
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