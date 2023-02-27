#include "URL/URL.h"

using namespace std::string_literals;

URL::URL(const std::string &_uri) : uri(_uri) {}

bool URL::operator==(const URL &other) {
    return uri == other.uri;
}

bool URL::operator==(URL &other) {
    return uri == other.uri;
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
