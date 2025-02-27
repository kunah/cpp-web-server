#include "URL/URL.h"

namespace url = ws::url;

url::URL::URL(const std::string &_uri) : uri(_uri) {
    ParseURL();
}

url::URL& url::URL::operator=(std::string &other) {
    uri = other;
    values.clear();
    ParseURL();
    return (*this);
}

url::URL& url::URL::operator=(const url::URL &other) {
    this->uri = other.uri;
    this->values = other.values;
    ParseURL();
    return (*this);
}

bool url::URL::operator==(url::URL &other) {
    return uri == other.uri;
}

bool url::URL::operator==(const std::string &otherUri) {
    return uri == otherUri;
}

bool url::URL::operator==(std::string &otherUri) {
    return uri == otherUri;
}

std::ostream& ws::url::operator<<(std::ostream &os, URL & url) {
    os << url.uri << std::endl;
    os << "Uri parts" << std::endl;
    for(size_t i = 0; i < url.parts.size() ; ++i)
        os << '\t' << i << " " << url.parts[i] << std::endl;
    return os;
}

std::string url::URL::GetURL() const {
    return uri;
}

std::vector<std::string> url::URL::GetParts() const {
    return parts;
}

std::unordered_map<std::string, std::string> url::URL::GetValues() const {
    return values;
}

void url::URL::SetValues(std::unordered_map<std::string, std::string>& _values) {
    values = _values;
}

void url::URL::ParseURL() {
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
