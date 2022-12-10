#ifndef CPP_WEB_SERVER_WEBSERVER_H
#define CPP_WEB_SERVER_WEBSERVER_H

#include <iostream>
#include <iomanip>
#include <string>


#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <chrono>

typedef struct sockaddr_in sockaddr_in;

class WebServer {
public:

    WebServer(uint16_t _port);

    void Run();

private:

    sockaddr_in address;
    int socketFD;
    uint16_t port;
};

std::ostream & PrintCurrentTime(std::ostream & io);

#endif //CPP_WEB_SERVER_WEBSERVER_H
