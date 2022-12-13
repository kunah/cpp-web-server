#ifndef CPP_WEB_SERVER_CLIENTREQUEST_H
#define CPP_WEB_SERVER_CLIENTREQUEST_H

#include <string>
#include <sys/socket.h>
#include <sys/select.h>
#include <unistd.h>

#include <ctime>
#include <sstream>

#include <Logger.h>
#include <HTTPParser.h>
#include <ServerMapping.h>
#include <States/HTTPState.h>

#define BUFFER_SIZE 1'000'000

class ClientRequest {
public:
    ClientRequest(int _socketFD);
    ~ClientRequest();

    ClientRequest(ClientRequest & _other) = delete;
    void operator=(ClientRequest & _other) = delete;

    void Run();
private:

    void ReadSocket();
    void SendResponse();

    HTTPParser request;

    HTTPParser response;

    int socketFD;
    fd_set socket;
    struct timeval timeout;

    std::shared_ptr<ServerMapping> mapping;
};


#endif //CPP_WEB_SERVER_CLIENTREQUEST_H
