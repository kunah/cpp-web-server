#include <ClientRequest.h>

ws::ClientRequest::ClientRequest(int _socketFD, const std::shared_ptr<Pipeline> pipeline) : socketFD(_socketFD), requestPipeline(pipeline) {
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    Logger::debug("ClientRequest created with max buffer size:", BUFFER_SIZE, "bytes");
}

ws::ClientRequest::~ClientRequest() {
    if(socketFD >= 0){
        Logger::debug("Closing connection", socketFD);
        if(close(socketFD))
            Logger::debug("Close connection problem:", strerror(errno));
    }
    Logger::debug("Destroying client request");
}

void ws::ClientRequest::ReadSocket() {

    int retVal;
    auto buffer = new unsigned char[BUFFER_SIZE];

    FD_ZERO(&socket);
    FD_SET(socketFD, &socket);

    retVal = select(socketFD + 1, &socket, nullptr, nullptr, &timeout);
    if(retVal < 0){
        Logger::error("Select problem:", strerror(errno));
        throw HTTPException::HTTPInternalServerError();
    }
    if(!FD_ISSET(socketFD, &socket)){
        Logger::info("Connection timeout!");
        throw HTTPException::HTTPRequestTimeout();
    }
    auto bytesRead = recv(socketFD, buffer, BUFFER_SIZE, 0);
    if(bytesRead < 0){
        Logger::error("Socket read error:", strerror(errno));
        throw HTTPException::HTTPInternalServerError();
    }
    std::vector<unsigned char> buf;
    std::copy(buffer, buffer + bytesRead, std::back_inserter(buf));
    delete [] buffer;

    Logger::debug("Requested message:\n", std::string(buf.begin(), buf.end()));

    Logger::debug("Previous buffer:", bytesRead, "Current Buffer", buf.size());


    request = http::HTTPContext(buf, bytesRead);
}

void ws::ClientRequest::SendResponse() {
    auto res = response.ToData();
    Logger::debug("Sending response: ", response.version);

    if (send(socketFD, res.data(), res.size(), MSG_NOSIGNAL) < 0) {
        Logger::error("Can't send data", strerror(errno));
        throw HTTPException::HTTPInternalServerError();
    }
}

void ws::ClientRequest::Run() {
    try{
        Logger::debug("Running Client request");
        ReadSocket();

        for(const auto & middleware : *requestPipeline){
            middleware->Run(request);
        }

        response = http::HTTPState(request.method).HandleRequest(request);
        SendResponse();
    }
    catch (HTTPException::HTTPExceptionBase & err){
        response = err.Response();
        SendResponse();
    }
    catch(...){
        response = HTTPException::HTTPInternalServerError().Response();
        SendResponse();
    }
}
