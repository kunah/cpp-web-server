#include <URL/URLMapper.h>

namespace url = ws::url;

url::internal::RegexPart::RegexPart(const std::string &_part) : regexPart(_part, flags), regexStr(_part){}

bool url::internal::RegexPart::operator==(const RegexPart &part) const {
    return std::regex_match(part.regexStr, regexPart);
}

std::string url::internal::RegexPart::GetRegex() const {
    return regexStr;
}

url::URLPart::URLPart(const std::string &_part) : part(_part), url("") {}

std::shared_ptr<url::URLPart> url::URLPart::AddDescendant(const std::string &newDesc) {
    auto res = descendants.find(newDesc);
    bool reg = newDesc.find("[[:alnum:]]+") != std::string::npos;
    if(res == descendants.end() && !reg){
        auto newPtr = std::make_shared<URLPart>(newDesc);
        descendants[newDesc] = newPtr;
        return newPtr;
    }
    else if(reg){
        auto regexRes = std::find_if(regexDescendants.begin(), regexDescendants.end(),[&newDesc](const std::pair<url::internal::RegexPart, std::shared_ptr<URLPart>> & t){
            return t.first.GetRegex() == newDesc;
        });
        if(regexRes == regexDescendants.end()){
            auto newPtr = std::make_shared<URLPart>(newDesc);
            regexDescendants.emplace_back(newDesc, newPtr);
            return newPtr;
        }
        return regexRes->second;
    }
    return res->second;
}

std::shared_ptr<url::URLPart> url::URLPart::FindDescendant(const std::string &nextPart) const {
    auto res = descendants.find(nextPart);
    if(res != descendants.end())
        return res->second;
    auto regexRes = std::find_if(regexDescendants.begin(), regexDescendants.end(), [&nextPart](const std::pair<url::internal::RegexPart, std::shared_ptr<URLPart>> & t){
        return t.first == nextPart;
    });
    return regexRes != regexDescendants.end() ? regexRes->second : std::shared_ptr<URLPart>(nullptr);
}

void url::URLPart::MapFunction(functionProcess _fnc, PatternURL _url) {
    if(fnc){
        Logger::error("Trying to register uri for the same method");
        throw std::runtime_error("Trying to register uri for the same method");
    }
    this->fnc = std::move(_fnc);
    url = _url;
}

url::functionProcess url::URLPart::GetFunction() const {
    return fnc;
}

const url::PatternURL & url::URLPart::GetURL() const {
    return url;
}

url::URLMapper::URLMapper() : root(std::make_shared<URLPart>("/")){}

void url::URLMapper::RegisterURL(const std::string &uri, functionProcess _fnc) {

    PatternURL newURL(uri);

    auto parts = newURL.GetParts();
    auto partPointer = root;

    for (auto & part : parts) {
        partPointer = partPointer->AddDescendant(part);
    }

    partPointer->MapFunction(_fnc, newURL);
}

std::pair<url::functionProcess, url::URL> url::URLMapper::FindURL(URL &uri) {

    auto parts = uri.GetParts();
    auto partPointer = root;

    for(auto & part : parts) {
        partPointer = partPointer->FindDescendant(part);
        if(!partPointer){
            Logger::error("URL not mapped", uri);
            throw HTTPException::HTTPNotFound();
        }
    }

    auto fnc = partPointer->GetFunction();
    if(!fnc){
        Logger::debug("Function is not mapped for this url", uri);
        throw HTTPException::HTTPNotFound();
    }

    auto url = partPointer->GetURL();
    if(!(url == uri)){
        Logger::error("URL is not matching, check it out", url.GetURL(), uri.GetURL());
        throw HTTPException::HTTPNotFound();
    }
    return {fnc, url};
}

std::pair<url::functionProcess, url::URL> url::URLMapper::FindURL(const std::string &uri) {
    URL url(uri);
    return FindURL(url);
}