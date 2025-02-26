#ifndef CPP_WEB_SERVER_CLIENTREQUEST_H
#define CPP_WEB_SERVER_CLIENTREQUEST_H

#include <string>
#include <ctime>
#include <cstring>
#include <sstream>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/select.h>

#include <Logger.h>
#include <HTTPResolver/HTTPParser.h>
#include <ServerMapping.h>
#include <HTTPResolver/States/HTTPState.h>
#include <HTTPResolver/Exceptions/ClientError.h>
#include <HTTPResolver/Exceptions/ServerError.h>

#define BUFFER_SIZE 1'000'000

namespace ws {

/// Class that handles clients request
    class ClientRequest {
    public:
        /// \param _socketFD File descriptor that refers to the socket
        ClientRequest(int _socketFD);

        ~ClientRequest();

        ClientRequest(ClientRequest &_other) = delete;

        void operator=(ClientRequest &_other) = delete;

        /// Handles client
        void Run();

    private:

        /// Reads data from the socket
        void ReadSocket();

        /// Sends response to the client
        void SendResponse();

        http::HTTPParser request;

        http::HTTPParser response;

        int socketFD;
        fd_set socket;
        struct timeval timeout;

        std::shared_ptr<_mapping::ServerMapping> mapping;
    };

}


#endif //CPP_WEB_SERVER_CLIENTREQUEST_H
