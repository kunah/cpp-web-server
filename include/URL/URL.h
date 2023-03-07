#ifndef CPP_WEB_SERVER_URL_H
#define CPP_WEB_SERVER_URL_H

#include <regex>
#include <string>
#include <vector>
#include <unordered_map>

#include <Logger.h>

class URL{
public:
    URL() = default;
    URL(const std::string & _uri);

    virtual ~URL() = default;

    URL& operator=(std::string & other);
    URL& operator=(const URL & other);

    virtual bool operator==(URL & other);
    virtual bool operator==(const std::string &otherUri);
    virtual bool operator==(std::string &otherUri);

    friend std::ostream& operator<<(std::ostream & os, URL & url);

    std::string GetURL() const;
    std::vector<std::string> GetParts() const;
    std::unordered_map<std::string, std::string> GetValues() const;
    void SetValues(std::unordered_map<std::string, std::string>& _values);

protected:

    void ParseURL();

    std::string uri;

    std::vector<std::string> parts;

    std::unordered_map<std::string, std::string> values;

};

#endif //CPP_WEB_SERVER_URL_H
