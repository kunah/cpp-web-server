#include "URL/URL.h"

using namespace std::string_literals;

URL::URL(const std::string &_uri) : uri(_uri) {}

URL& URL::operator=(std::string &other) {
    uri = other;
    values.clear();
    return (*this);
}

URL& URL::operator=(const URL &other) {
    this->uri = other.uri;
    this->values = other.values;
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
    os << url.uri;
    return os;
}

std::string URL::GetURL() const {
    return uri;
}

std::unordered_map<std::string, std::string> URL::GetValues() const {
    return values;
}

void URL::SetValues(std::unordered_map<std::string, std::string>& _values) {
    values = _values;
}
