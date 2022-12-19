#include "ClientRequest.h"

ClientRequest::ClientRequest(int _socketFD) : socketFD(_socketFD), mapping(ServerMapping::Instance()){
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    Logger::debug("ClientRequest created with max buffer size:", BUFFER_SIZE, "bytes");
}

ClientRequest::~ClientRequest() {
    if(socketFD >= 0){
        Logger::debug("Closing connection", socketFD);
        if(close(socketFD))
            Logger::debug("Close connection problem:", strerror(errno));
    }
    Logger::debug("Destroying client request");
}

void ClientRequest::ReadSocket() {

    int retVal;
    auto buffer = std::make_shared<unsigned char>(BUFFER_SIZE);

    FD_ZERO(&socket);
    FD_SET(socketFD, &socket);

    retVal = select(socketFD + 1, &socket, nullptr, nullptr, &timeout);
    if(retVal < 0){
        Logger::error("Select problem:", strerror(errno));
        throw std::runtime_error("Select problem");
    }
    if(!FD_ISSET(socketFD, &socket)){
        Logger::info("Connection timeout!");
        return;
    }
    auto bytesRead = recv(socketFD, buffer.get(), BUFFER_SIZE, 0);
    if(bytesRead < 0){
        Logger::error("Socket read error:", strerror(errno));
        throw std::runtime_error("Socket read");
    }
    Logger::debug("Requested message:\n", buffer.get());

    request = HTTPParser(buffer, bytesRead);
}

void ClientRequest::SendResponse() {
    auto res = response.ToString();
    Logger::debug("Sending response", res);

    if (send(socketFD, res.c_str(), res.size(), MSG_NOSIGNAL) < 0) {
        Logger::error("Can't send data", strerror(errno));
        throw std::runtime_error("Can't send data to client");
    }
}

void ClientRequest::Run() {
    try{
        Logger::debug("Running Client request");
        ReadSocket();
        HTTPState state(request.method);
        response = state.HandleRequest(request);
        SendResponse();
    }
    catch (HTTPError::ClientError & err){
        response = err.Response();
        SendResponse();
    }
    catch(...){
        response = HTTPError::HTTPNotFound().Response();
        response.version = "HTTP/1.1 500 Server Error";
        SendResponse();
    }
}
