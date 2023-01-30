#include <States/HTTPState.h>


HTTPState::HTTPState(HTTPMethod _method) : method(_method) {}

void HTTPState::SetState(HTTPMethod requestMethod) {
    method = requestMethod;
}

HTTPParser HTTPState::HandleRequest(HTTPParser &request) {
    auto uris = ServerMapping::Instance()->GetURIs(method);

    auto process = uris.find(request.uri);

    if(process == uris.end()){
        Logger::error("Request URI is not mapped", request.uri);
        throw HTTPException::HTTPNotFound();
    }
    return process->second()->Process(request);
}