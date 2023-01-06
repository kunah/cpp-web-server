#ifndef CPP_WEB_SERVER_HTTPMETHOD_H
#define CPP_WEB_SERVER_HTTPMETHOD_H

/// Methods in HTTP
// TODO: hashes are calculated on different devices differently
enum HTTPMethod{ // std::hash of std::string(method) cropped to unsigned int
    GET = 1158220111,
    PUT = 795930711,
    POST = 2893932544,
    HEAD = 43864722,
    DELETE = 1462665631,
    CONNECT = 2484980613,
    OPTIONS = 1947229628,
    TRACE = 1138122765,
    PATCH = 2564937511
};

#endif //CPP_WEB_SERVER_HTTPMETHOD_H
