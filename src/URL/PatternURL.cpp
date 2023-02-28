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

    auto otherUrl = other.GetURL();

    if (!(*this == otherUrl))
        return false;

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

    Logger::debug(uri, "->", RegexUriBase, "->", otherUrl);

    Logger::debug("Dynamic values");
    for(auto & it : otherVal){
        Logger::debug("\t", it.first, it.second);
    }

    other.SetValues(otherVal);
    return true;
}


bool PatternURL::operator==(std::string &otherUri) {
    return std::regex_match(otherUri, RegexUri);
}

bool PatternURL::operator==(const std::string &otherUri) {
    return std::regex_match(otherUri, RegexUri);
}

void PatternURL::Print() {

    std::cout << uri << " -> " << RegexUriBase << std::endl;

    std::cout << "Dynamic values" << std::endl;
    for(auto & it : dynamicURLMapping){
        std::cout << "\t" << it.first << " " << it.second << std::endl;
    }
}
