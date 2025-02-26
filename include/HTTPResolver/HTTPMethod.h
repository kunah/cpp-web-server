#ifndef CPP_WEB_SERVER_HTTPMETHOD_H
#define CPP_WEB_SERVER_HTTPMETHOD_H

namespace ws::http {

/// Methods in HTTP
    enum HTTPMethod {
        GET = 1,
        PUT,
        POST,
        HEAD,
        DELETE,
        CONNECT,
        OPTIONS,
        TRACE,
        PATCH
    };

}

#endif //CPP_WEB_SERVER_HTTPMETHOD_H
