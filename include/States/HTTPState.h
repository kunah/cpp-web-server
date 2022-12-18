#ifndef CPP_WEB_SERVER_HTTPSTATE_H
#define CPP_WEB_SERVER_HTTPSTATE_H

#include <memory>
#include <fstream>
#include <chrono>
#include <iomanip>

#include <HTTPParser.h>
#include <ServerMapping.h>
#include <Logger.h>
#include <Exceptions/ClientError.h>

class HTTPState {
public:
    HTTPState(HTTPMethod _method);

    HTTPParser HandleRequest(HTTPParser & request);

    void SetState(HTTPMethod requestMethod);

protected:
    HTTPMethod method;
};


#endif //CPP_WEB_SERVER_HTTPSTATE_H
