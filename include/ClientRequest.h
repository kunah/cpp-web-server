#ifndef CPP_WEB_SERVER_CLIENTREQUEST_H
#define CPP_WEB_SERVER_CLIENTREQUEST_H

#include <vector>
#include <string>
#include <ctime>
#include <cstring>
#include <sstream>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/select.h>

#include <Logger.h>
#include <ServerMapping.h>
#include <interface/Middleware.h>
#include <HTTPResolver/HTTPContext.h>
#include <HTTPResolver/States/HTTPState.h>
#include <HTTPResolver/Exceptions/ClientError.h>
#include <HTTPResolver/Exceptions/ServerError.h>

#define BUFFER_SIZE 1'000'000

namespace ws {

    typedef std::vector<std::shared_ptr<ws::interface::Middleware>> Pipeline;

    /// Class that handles clients request
    class ClientRequest {
    public:
        /// \param _socketFD File descriptor that refers to the socket
        ClientRequest(int _socketFD, const std::shared_ptr<Pipeline> pipeline);

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

        http::HTTPContext request;

        http::HTTPContext response;

        int socketFD;
        fd_set socket;
        struct timeval timeout;

        const std::shared_ptr<Pipeline> requestPipeline;
    };

} // namespace ws


#endif //CPP_WEB_SERVER_CLIENTREQUEST_H
