#include "WebServer.h"

#define MODE AF_INET

WebServer::WebServer(uint16_t _port) : port(_port), pool(5) {
    Logger::info("Starting Web server on port", port);

    if(port == 0){
        Logger::error("This port can't be used", port);
        throw std::invalid_argument("Wrong port");
    }

    // creating socket
    socketFD = socket(MODE, SOCK_STREAM, 0);
    if(socketFD < 0){
        Logger::error("Can't create socket:", strerror(errno));
        throw std::runtime_error("Can't create socket");
    }

    // setting socket address
    bzero(&address, sizeof(address));
    address.sin_family = MODE;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(INADDR_ANY);

    // assign address to socket
    if(bind(socketFD, (struct sockaddr *) &address, sizeof(address)) < 0){
        Logger::error("Problem with bind():", strerror(errno));
        close(socketFD);
        throw std::runtime_error("Can't assign address to socket");
    }

    // start listeningx max 10 clients
    Logger::debug("Setting up listening mode on socket", socketFD);
    if(listen(socketFD, 10) < 0){
        Logger::error("Can't start listening:", strerror(errno));
        close(socketFD);
        throw std::runtime_error("Can't listen");
    }

//    Logger::info("Adding default mapping");
//    ServerMapping::RegisterURI(HTTPMethod::GET, "/", "dist/index.html");
    Logger::info("Server prepared");
}

void WebServer::Run() {

    Logger::info("Server listening on port", port);

    while(true){

        sockaddr_in remoteAddress;
        socklen_t size = sizeof(remoteAddress);
        bzero(&remoteAddress, size);

        char ipAddress[INET_ADDRSTRLEN];

        // waiting for new connection
        int newConnectionFD = accept(socketFD, (struct sockaddr *) &remoteAddress, &size);
        if (newConnectionFD < 0){
            Logger::error("Problem with accepting connection:", strerror(errno));
            throw std::runtime_error("Can't accept connection (error code " + std::to_string(newConnectionFD) + ")");
        }
        inet_ntop(MODE, &remoteAddress.sin_addr.s_addr, ipAddress, INET_ADDRSTRLEN);
        Logger::info("Connection received");
        Logger::debug("Connection received", ipAddress);

        pool.Add(newConnectionFD);

        if(socketFD == -1)
            break;
    }

}