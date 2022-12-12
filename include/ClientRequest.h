#ifndef CPP_WEB_SERVER_CLIENTREQUEST_H
#define CPP_WEB_SERVER_CLIENTREQUEST_H

#include <string>
#include <sys/socket.h>
#include <sys/select.h>
#include <unistd.h>

#include <Logger.h>

#define BUFFER_SIZE 1'000'000

class ClientRequest {
public:
    ClientRequest(int _socketFD);
    ~ClientRequest();

    ClientRequest(ClientRequest & _other) = delete;
    void operator=(ClientRequest & _other) = delete;

    static void Run(int socketFD);
private:

    void ReadSocket();

    std::string requestData;

    int socketFD;
    fd_set socket;
    struct timeval timeout;

};


#endif //CPP_WEB_SERVER_CLIENTREQUEST_H
