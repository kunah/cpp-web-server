#ifndef CPP_WEB_SERVER_URLMAPPER_H
#define CPP_WEB_SERVER_URLMAPPER_H

#include <memory>
#include <string>
#include <unordered_map>

#include <Logger.h>
#include <URL/PatternURL.h>
#include <Exceptions/ClientError.h>
#include <ProcessClasses/BaseHTTPProcess.h>

typedef std::function<std::shared_ptr<BaseHTTPProcess>()> functionProcess;

class URLPart{
public:
    URLPart(const std::string & _part);

    ~URLPart() = default;

    std::shared_ptr<URLPart> AddDescendant(const std::string & newDesc);
    std::shared_ptr<URLPart> FindDescendant(const std::string & nextPart) const;
    void MapFunction(functionProcess _fnc, PatternURL _url);
    functionProcess GetFunction() const;
    const PatternURL & GetURL() const;

private:

    std::string part;

    PatternURL url;

    functionProcess fnc;

    std::unordered_map<std::string, std::shared_ptr<URLPart>> descendants;

    std::shared_ptr<URLPart> regexDescendant;
};

class URLMapper{
public:
    URLMapper();

    ~URLMapper() = default;

    void RegisterURL(const std::string & uri, functionProcess _fnc);

    std::pair<functionProcess, URL>  FindURL(const std::string & uri);


private:

    std::shared_ptr<URLPart> root;


};

#endif //CPP_WEB_SERVER_URLMAPPER_H
