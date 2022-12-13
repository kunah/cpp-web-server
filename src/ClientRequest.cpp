#include "ClientRequest.h"

ClientRequest::ClientRequest(int _socketFD) : socketFD(_socketFD), mapping(ServerMapping::Instance()){
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    Logger::debug("ClientRequest created with max buffer size:", BUFFER_SIZE, "bytes");
}

ClientRequest::~ClientRequest() {
    if(socketFD >= 0){
        Logger::debug("Closing connection", socketFD);
        close(socketFD);
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

    HTTPParser request(buffer, bytesRead);

    auto map = mapping->GetMapping(request.uri);

    std::fstream file(map.string());

    if(!file.is_open()){
        Logger::error("Can't open file", map);
        throw std::runtime_error("Can't open file for given mapping");
    }
    std::string fileInfo, tmp;
    while(file.good()){
        std::getline(file, tmp);
        fileInfo.append(tmp);
    }
    file.close();
    Logger::debug("Content of", map, fileInfo);

    HTTPParser response;
    auto in_time_t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
    response.header["Date"] = ss.str();
    response.header["Content-Length"] = std::to_string(fileInfo.size());
    response.header["Content-Type"] = "text/html";
    response.header["Connection"] = "Closed";
    response.body = fileInfo;
    response.version = "HTTP/1.1 200 OK";

    auto res = response.ToString();
    Logger::debug("Sending response", res);

    if (send(socketFD, res.c_str(), res.size(), MSG_NOSIGNAL) < 0) {
        Logger::error("Can't send data", strerror(errno));
        throw std::runtime_error("Can't send data to client");
    }

}

void ClientRequest::Run() {
    Logger::debug("Running Client request");
    ReadSocket();
}
