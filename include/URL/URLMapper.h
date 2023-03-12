#ifndef CPP_WEB_SERVER_URLMAPPER_H
#define CPP_WEB_SERVER_URLMAPPER_H

#include <map>
#include <memory>
#include <string>
#include <unordered_map>

#include <Logger.h>
#include <URL/PatternURL.h>
#include <Exceptions/ClientError.h>
#include <ProcessClasses/BaseHTTPProcess.h>

typedef std::function<std::shared_ptr<BaseHTTPProcess>()> functionProcess;

class RegexPart{
public:
    RegexPart(const std::string & _part);
    bool operator==(const RegexPart & part) const;
    std::string GetRegex() const;
private:
    std::regex::flag_type flags =
//            = std::regex::flag_type{0}
            // Choose one of the supported grammars:
            std::regex::ECMAScript
//              | std::regex::basic
//              | std::regex::extended
//              | std::regex::awk
//              | std::regex::grep
//              | std::regex::egrep
    // Choose any of the next options:
//              | std::regex::icase
//              | std::regex::nosubs
//              | std::regex::optimize
//              | std::regex::collate
    ;
    std::regex regexPart;
    std::string regexStr;

};

namespace std{
    template<>
    struct hash<RegexPart>{
        std::size_t operator()(const RegexPart& part) const{
            return std::hash<std::string>()(part.GetRegex());
        }
    };
}

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

    std::unordered_map<RegexPart, std::shared_ptr<URLPart>> descendants;

    // TODO: implement more regex parts of an url and be able to search in them
    std::vector<std::pair<RegexPart, std::shared_ptr<URLPart>>> regexDescendants;
};

class URLMapper{
public:
    URLMapper();

    ~URLMapper() = default;

    void RegisterURL(const std::string & uri, functionProcess _fnc);

    std::pair<functionProcess, URL>  FindURL(URL & uri);
    std::pair<functionProcess, URL>  FindURL(const std::string & uri);


private:

    std::shared_ptr<URLPart> root;


};

#endif //CPP_WEB_SERVER_URLMAPPER_H
