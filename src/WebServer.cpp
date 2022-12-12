#include "WebServer.h"

#define MODE AF_INET

WebServer::WebServer(uint16_t _port) : port(_port) {
    std::cout << "Starting Web server on port " << port << std::endl;

    if(port == 0){
        std::cerr << "This port can't be used" << std::endl;
        throw std::invalid_argument("Wrong port");
    }

    // creating socket
    socketFD = socket(MODE, SOCK_STREAM, 0);
    if(socketFD < 0){
        perror("Can't create socket: ");
        throw std::runtime_error("Can't create socket");
    }

    // setting socket address
    bzero(&address, sizeof(address));
    address.sin_family = MODE;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(INADDR_ANY);

    // assign address to socket
    if(bind(socketFD, (struct sockaddr *) &address, sizeof(address)) < 0){
        perror("Problem s bind(): ");
        close(socketFD);
        throw std::runtime_error("Can't assign address to socket");
    }

    // start listeningx max 10 clients
    std::cout << "Setting up listening mode on socket " << socketFD << std::endl;
    if(listen(socketFD, 10) < 0){
        perror("Can't start listening: ");
        close(socketFD);
        throw std::runtime_error("Can't listen");
    }

    std::cout << "Server prepared" << std::endl;
}

void WebServer::Run() {

    std::cout << "Server listening on port " << port << std::endl;

    while(true){

        sockaddr_in remoteAddress;
        socklen_t size = sizeof(remoteAddress);
        bzero(&remoteAddress, size);

        char ipAddress[INET_ADDRSTRLEN];

        // waiting for new connection
        int newConnectionID = accept(socketFD, (struct sockaddr *) &remoteAddress, &size);
        if (newConnectionID < 0){
            perror("Problem with accepting connection: ");
            throw std::runtime_error("Can't accept connection (error code " + std::to_string(newConnectionID) + ")");
        }
        inet_ntop(MODE, &remoteAddress.sin_addr.s_addr, ipAddress, INET_ADDRSTRLEN);
        Logger::info(std::string("Connection received ") + ipAddress);

        if(socketFD == -1)
            break;
    }

}