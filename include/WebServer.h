#ifndef CPP_WEB_SERVER_WEBSERVER_H
#define CPP_WEB_SERVER_WEBSERVER_H

#include <iostream>
#include <string>
#include <cstring>

#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <Logger.h>
#include <ThreadPool.h>
#include <ServerMapping.h>

typedef struct sockaddr_in sockaddr_in;

class WebServer {
public:
    /// Default constructor for webserver
    /// \param _port port to bind
    WebServer(uint16_t _port);

    /// Runs the server
    void Run();

private:

    sockaddr_in address;
    int socketFD;
    uint16_t port;

    ThreadPool pool;
};

#endif //CPP_WEB_SERVER_WEBSERVER_H
