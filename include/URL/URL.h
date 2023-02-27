#ifndef CPP_WEB_SERVER_URL_H
#define CPP_WEB_SERVER_URL_H

#include <regex>
#include <string>
#include <unordered_map>

#include "Logger.h"

class URL{
public:
    URL() = default;
    URL(const std::string & _uri);

    virtual ~URL() = default;

    virtual bool operator==(const URL & other);
    virtual bool operator==(URL & other);

    std::string GetURL() const;
    std::unordered_map<std::string, std::string> GetValues() const;
    void SetValues(std::unordered_map<std::string, std::string>& _values);

protected:


    std::string uri;

    std::unordered_map<std::string, std::string> values;

};

#endif //CPP_WEB_SERVER_URL_H
