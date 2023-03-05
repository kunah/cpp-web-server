#include <URL/URLMapper.h>

URLPart::URLPart(const std::string &_part) : part(_part), url(""), regexDescendant(nullptr){}

std::shared_ptr<URLPart> URLPart::AddDescendant(const std::string &newDesc) {
    auto res = descendants.find(newDesc);
    bool reg = newDesc == "[[:alnum:]]+";
    if(res == descendants.end() && !reg){
        auto newPtr = std::make_shared<URLPart>(newDesc);
        descendants[newDesc] = newPtr;
        return newPtr;
    }
    else if(reg){
        if(!regexDescendant)
            regexDescendant = std::make_shared<URLPart>(newDesc);
        return regexDescendant;
    }
    return res->second;
}

std::shared_ptr<URLPart> URLPart::FindDescendant(const std::string &nextPart) const {
    auto res = descendants.find(nextPart);
    if(res != descendants.end())
        return res->second;
    return regexDescendant ? regexDescendant : std::shared_ptr<URLPart>(nullptr);
}

void URLPart::MapFunction(functionProcess _fnc, PatternURL _url) {
    if(fnc){
        Logger::error("Trying to register uri for the same method");
        throw std::runtime_error("Trying to register uri for the same method");
    }
    this->fnc = std::move(_fnc);
    url = _url;
}

functionProcess URLPart::GetFunction() const {
    return fnc;
}

const PatternURL & URLPart::GetURL() const {
    return url;
}

URLMapper::URLMapper() : root(std::make_shared<URLPart>("/")){}

void URLMapper::RegisterURL(const std::string &uri, functionProcess _fnc) {

    PatternURL newURL(uri);

    auto parts = newURL.GetParts();
    auto partPointer = root;

    for (auto & part : parts) {
        partPointer = partPointer->AddDescendant(part);
    }

    partPointer->MapFunction(_fnc, newURL);
}

std::pair<functionProcess, URL> URLMapper::FindURL(const std::string &uri) {
    URL requestedURL(uri);

    auto parts = requestedURL.GetParts();
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
    if(!(url == requestedURL)){
        Logger::error("URL is not matching, check it out", url.GetURL(), requestedURL.GetURL());
        throw HTTPException::HTTPNotFound();
    }
    return {fnc, url};
}