#include <ClientRequest.h>

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
    Logger::debug("Requested message:\n", buffer);

    std::vector<unsigned char> buf;
    std::copy(buffer, buffer + bytesRead, std::back_inserter(buf));
    delete [] buffer;

    Logger::debug("Previous buffer:", bytesRead, "Current Buffer", buf.size());


    request = HTTPParser(buf, bytesRead);
}

void ClientRequest::SendResponse() {
    auto res = response.ToData();
    Logger::debug("Sending response: ", response.version);

    if (send(socketFD, res.data(), res.size(), MSG_NOSIGNAL) < 0) {
        Logger::error("Can't send data", strerror(errno));
        throw HTTPException::HTTPInternalServerError();
    }
}

void ClientRequest::Run() {
    try{
        Logger::debug("Running Client request");
        ReadSocket();
        response = HTTPState(request.method).HandleRequest(request);
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
