#ifndef CPP_WEB_SERVER_CLIENTREQUEST_H
#define CPP_WEB_SERVER_CLIENTREQUEST_H

#include <string>
#include <sys/socket.h>
#include <sys/select.h>
#include <unistd.h>

#include <ctime>
#include <cstring>
#include <sstream>

#include <Logger.h>
#include <HTTPParser.h>
#include <ServerMapping.h>
#include <States/HTTPState.h>
#include <Exceptions/ClientError.h>
#include <Exceptions/ServerError.h>

#define BUFFER_SIZE 1'000'000

/// Class thah handles clients request
class ClientRequest {
public:
    /// \param _socketFD File descriptor that refers to the socket
    ClientRequest(int _socketFD);
    ~ClientRequest();

    ClientRequest(ClientRequest & _other) = delete;
    void operator=(ClientRequest & _other) = delete;

    /// Handles client
    void Run();
private:

    /// Reads data from the socket
    void ReadSocket();
    /// Sends response to the client
    void SendResponse();

    HTTPParser request;

    HTTPParser response;

    int socketFD;
    fd_set socket;
    struct timeval timeout;

    std::shared_ptr<ServerMapping> mapping;
};


#endif //CPP_WEB_SERVER_CLIENTREQUEST_H
