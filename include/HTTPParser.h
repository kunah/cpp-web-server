#ifndef CPP_WEB_SERVER_HTTPPARSER_H
#define CPP_WEB_SERVER_HTTPPARSER_H


class HTTPParser {
public:
    /// Methods in HTTP
    enum HTTPMethod{
        GET = 0,
        PUT,
        POST,
        HEAD,
        DELETE,
        CONNECT,
        OPTIONS,
        TRACE,
        PATCH
    };

private:

};


#endif //CPP_WEB_SERVER_HTTPPARSER_H
