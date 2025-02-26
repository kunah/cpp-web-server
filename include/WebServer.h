#ifndef CPP_WEB_SERVER_WEBSERVER_H
#define CPP_WEB_SERVER_WEBSERVER_H

#include <string>
#include <cstring>
#include <iostream>

#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <Logger.h>
#include <ThreadPool.h>
#include <ServerMapping.h>

namespace ws {

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

        threads::ThreadPool pool;
    };
}
#endif //CPP_WEB_SERVER_WEBSERVER_H
