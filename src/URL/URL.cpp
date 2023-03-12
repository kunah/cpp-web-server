#include "URL/URL.h"

using namespace std::string_literals;

URL::URL(const std::string &_uri) : uri(_uri) {
    ParseURL();
}

URL& URL::operator=(std::string &other) {
    uri = other;
    values.clear();
    ParseURL();
    return (*this);
}

URL& URL::operator=(const URL &other) {
    this->uri = other.uri;
    this->values = other.values;
    ParseURL();
    return (*this);
}

bool URL::operator==(URL &other) {
    return uri == other.uri;
}

bool URL::operator==(const std::string &otherUri) {
    return uri == otherUri;
}

bool URL::operator==(std::string &otherUri) {
    return uri == otherUri;
}

std::ostream& operator<<(std::ostream &os, URL & url) {
    os << url.uri << std::endl;
    os << "Uri parts" << std::endl;
    for(size_t i = 0; i < url.parts.size() ; ++i)
        os << '\t' << i << " " << url.parts[i] << std::endl;
    return os;
}

std::string URL::GetURL() const {
    return uri;
}

std::vector<std::string> URL::GetParts() const {
    return parts;
}

std::unordered_map<std::string, std::string> URL::GetValues() const {
    return values;
}

void URL::SetValues(std::unordered_map<std::string, std::string>& _values) {
    values = _values;
}

void URL::ParseURL() {
    parts.clear();
    std::string tmp;
    for(auto & ch : uri){
        if(ch == '/'){
            if(tmp.size() > 0){
                parts.emplace_back(tmp);
                tmp.clear();
            }
            continue;
        }
        tmp.push_back(ch);
    }
    if(!tmp.empty())
        parts.emplace_back(tmp);
}
