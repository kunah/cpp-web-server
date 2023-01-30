#include <URL/PatternURL.h>

PatternURL::PatternURL(const std::string &_uri) : URL(_uri){

    auto words_begin = std::sregex_iterator(uri.begin(), uri.end(), words);
    auto words_end = std::sregex_iterator();

    int count = 0;

    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
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

bool PatternURL::operator==(const URL &other) {
    return std::regex_match(other.GetURL(), RegexUri);
}

void PatternURL::Print() {

    std::cout << uri << " -> " << RegexUriBase << std::endl;

    std::cout << "Dynamic values" << std::endl;
    for(auto & it : dynamicURLMapping){
        std::cout << "\t" << it.first << " " << it.second << std::endl;
    }
}
