#include <URL/PatternURL.h>

PatternURL::PatternURL(const std::string &_uri) : URL(_uri){

    auto wordsBegin = std::sregex_iterator(uri.begin(), uri.end(), words);
    auto wordsEnd = std::sregex_iterator();

    int count = 0;

    for (std::sregex_iterator i = wordsBegin; i != wordsEnd; ++i) {
        std::smatch match = *i;

        std::string matched = match.str();
        if(std::regex_match(matched, uriPattern)){
            std::smatch sm;
            std::regex_search(matched, sm ,replacePatter);
            dynamicURLMapping[count] = sm[0];
        }
        ++count;
    }

    RegexUriBase = std::regex_replace(uri, uriPattern, replacePatterString);
    RegexUri = std::regex(RegexUriBase, flags);
}

bool PatternURL::operator==(URL& other) {
    if (!std::regex_match(other.GetURL(), RegexUri))
        return false;

    auto otherUrl = other.GetURL();
    auto otherVal = other.GetValues();

    auto wordsBegin = std::sregex_iterator(otherUrl.begin(), otherUrl.end(), replacePatter);
    auto wordsEnd = std::sregex_iterator();

    int count = 0;

    for (std::sregex_iterator i = wordsBegin; i != wordsEnd; ++i, ++count) {
        std::smatch match = *i;
        auto res = dynamicURLMapping.find(count);
        if(res != dynamicURLMapping.end()){
            otherVal[res->second] = match.str();
        }
    }

    std::cout << uri << " -> " << RegexUriBase << " -> " << otherUrl << std::endl;

    std::cout << "Dynamic values" << std::endl;
    for(auto & it : otherVal){
        std::cout << "\t" << it.first << " " << it.second << std::endl;
    }

    other.SetValues(otherVal);
    return true;
}

void PatternURL::Print() {

    std::cout << uri << " -> " << RegexUriBase << std::endl;

    std::cout << "Dynamic values" << std::endl;
    for(auto & it : dynamicURLMapping){
        std::cout << "\t" << it.first << " " << it.second << std::endl;
    }
}
