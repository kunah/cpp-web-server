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

#include <interface/Middleware.h>

namespace ws {

    typedef struct sockaddr_in sockaddr_in;
    class WebServer {
    public:

        /// Default constructor for webserver
        /// \param _port port to bind
        /// \param pipeline pipeline that will handle the incoming request
        WebServer(uint16_t _port, std::shared_ptr<Pipeline> pipeline = nullptr);

        /// Runs the server
        void Run();

    private:

        sockaddr_in address;
        int socketFD;
        uint16_t port;

        threads::ThreadPool pool;
    };
} // namespace wsa
#endif //CPP_WEB_SERVER_WEBSERVER_H
