#ifndef CPP_WEB_SERVER_HTTPSTATE_H
#define CPP_WEB_SERVER_HTTPSTATE_H

#include <memory>
#include <chrono>
#include <vector>
#include <iomanip>
#include <fstream>

#include <Logger.h>
#include <HTTPParser.h>
#include <ServerMapping.h>
#include <Exceptions/ClientError.h>

/// Class that behaves based on HTTP method
class HTTPState {
public:
    HTTPState(HTTPMethod _method);

    /// \param request request to handle
    /// \return response in HTTPParser
    HTTPParser HandleRequest(HTTPParser & request);

    void SetState(HTTPMethod requestMethod);

protected:
    HTTPMethod method;
};


#endif //CPP_WEB_SERVER_HTTPSTATE_H
