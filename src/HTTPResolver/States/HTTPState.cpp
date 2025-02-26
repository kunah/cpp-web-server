#include <HTTPResolver/States/HTTPState.h>

using namespace ws::http;

HTTPState::HTTPState(HTTPMethod _method) : method(_method) {}

void HTTPState::SetState(HTTPMethod requestMethod) {
    method = requestMethod;
}

HTTPParser HTTPState::HandleRequest(HTTPParser &request) {
//    auto uris = ServerMapping::Instance()->GetURIs(method);

//    auto process = std::find_if(uris.begin(), uris.end(),
//                                [&request](std::pair<PatternURL, functionProcess> & posUrl){return posUrl.first == request.url;});
//
//    if(process == uris.end()){
//        Logger::error("Request URI is not mapped", request.url);
//        throw HTTPException::HTTPNotFound();
//    }

    auto process = _mapping::ServerMapping::Instance()->GetProcess(request.method, request.url);

    return process()->Process(request);
}