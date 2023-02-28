#ifndef CPP_WEB_SERVER_PATTERNURL_H
#define CPP_WEB_SERVER_PATTERNURL_H

#include <string>
#include <unordered_map>

#include <URL/URL.h>
#include <Logger.h>

class PatternURL : public URL{
public:

    PatternURL(const std::string & _uri);

    ~PatternURL() override = default;

    bool operator==( URL & other) override;
    bool operator==( std::string & otherUri) override;
    bool operator==( const std::string & otherUri) override;

    void Print();

private:

    std::string RegexUriBase;
    std::regex RegexUri;

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
    std::regex words = std::regex("\\{?[[:alnum:]]+\\}?", flags);
    std::regex uriPattern = std::regex("\\{[[:alnum:]]+\\}", flags);
    std::regex replacePatter = std::regex("[[:alnum:]]+", flags);
    std::string replacePatterString = "[[:alnum:]]+";

    std::unordered_map<int, std::string> dynamicURLMapping;

};

#endif //CPP_WEB_SERVER_PATTERNURL_H
