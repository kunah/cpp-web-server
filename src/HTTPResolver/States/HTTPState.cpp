#include <HTTPResolver/States/HTTPState.h>

namespace http = ws::http;

http::HTTPState::HTTPState(HTTPMethod _method) : method(_method) {}

void http::HTTPState::SetState(HTTPMethod requestMethod) {
    method = requestMethod;
}

http::HTTPContext http::HTTPState::HandleRequest(HTTPContext &request) {
//    auto uris = ServerMapping::Instance()->GetURIs(method);

//    auto process = std::find_if(uris.begin(), uris.end(),
//                                [&request](std::pair<PatternURL, functionProcess> & posUrl){return posUrl.first == request.url;});
//
//    if(process == uris.end()){
//        Logger::error("Request URI is not mapped", request.url);
//        throw HTTPException::HTTPNotFound();
//    }

    auto process = ws::internal::ServerMapping::Instance()->GetProcess(request.method, request.url);

    return process()->Process(request);
}