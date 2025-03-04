#ifndef CPP_WEB_SERVER_HTTPSTATE_H
#define CPP_WEB_SERVER_HTTPSTATE_H

#include <memory>
#include <chrono>
#include <vector>
#include <iomanip>
#include <fstream>

#include <Logger.h>
#include <HTTPResolver/HTTPContext.h>
#include <ServerMapping.h>
#include <HTTPResolver/Exceptions/ClientError.h>

namespace ws::http {

    /// Class that behaves based on HTTP method
    class HTTPState {
    public:
        HTTPState(HTTPMethod _method);

        /// \param request request to handle
        /// \return response in HTTPParser
        HTTPContext HandleRequest(HTTPContext &request);

        void SetState(HTTPMethod requestMethod);

    protected:
        HTTPMethod method;
    };

} // namespace ws::http

#endif //CPP_WEB_SERVER_HTTPSTATE_H
