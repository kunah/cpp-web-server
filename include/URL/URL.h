#ifndef CPP_WEB_SERVER_URL_H
#define CPP_WEB_SERVER_URL_H

#include <string>
#include <regex>

#include "Logger.h"

class URL{
public:
    URL() = default;
    URL(const std::string & _uri);

    virtual ~URL() = default;

    virtual bool operator==(const URL & other);

    std::string GetURL() const;
    std::unordered_map<std::string, std::string> GetValues() const;

protected:

    std::string uri;

    std::unordered_map<std::string, std::string> values;

};

#endif //CPP_WEB_SERVER_URL_H
