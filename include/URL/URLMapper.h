#ifndef CPP_WEB_SERVER_URLMAPPER_H
#define CPP_WEB_SERVER_URLMAPPER_H

#include <map>
#include <memory>
#include <string>
#include <unordered_map>

#include <Logger.h>
#include <URL/PatternURL.h>
#include <HTTPResolver/Exceptions/ClientError.h>
#include <HTTPResolver/ProcessClasses/BaseHTTPProcess.h>

namespace ws::url::_internal {

    /// Class for storing the regex part of an URL
    class RegexPart {
    public:
        /// Basic constructor for the URL part
        /// \param _part the string of the part
        RegexPart(const std::string &_part);

        /// \param part part to compare with
        /// \return compares if two parts are identical
        bool operator==(const RegexPart &part) const;

        /// \return string representation of the part
        std::string GetRegex() const;

    private:
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
        std::regex regexPart;
        std::string regexStr;

    };
}

namespace std{
    /// The hash function for RegexPart
    template<>
    struct hash<ws::url::_internal::RegexPart>{
        /// \param part the part to compute the hash
        /// \return the hash of the part
        std::size_t operator()(const ws::url::_internal::RegexPart& part) const{
            return std::hash<std::string>()(part.GetRegex());
        }
    };
}

namespace ws::url {

    typedef std::function<std::shared_ptr<http::BaseHTTPProcess>()> functionProcess;

    /// Class is used to build a hierarchy tree for searching mapped URLs
    /// Correct URLs contain the whole URL and process function
    class URLPart {
    public:
        /// The basic constructor of a URL part
        /// \param _part the string of the URL part
        URLPart(const std::string &_part);

        ~URLPart() = default;

        /// Add a new descendant to this URL part
        /// \param newDesc string for creating a new URL part
        /// \return pointer to the newly created URL part or pointer to the already existing part
        std::shared_ptr<URLPart> AddDescendant(const std::string &newDesc);

        /// \param nextPart the string for the desired part
        /// \return finds whenever this URLPart contains the next Part or nullptr
        std::shared_ptr<URLPart> FindDescendant(const std::string &nextPart) const;

        /// Maps the given function and the whole URL for this URLPart
        /// \param _fnc the process function for this ended URL
        /// \param _url the whole URL
        void MapFunction(functionProcess _fnc, PatternURL _url);

        /// \return the process function for this URLPart
        functionProcess GetFunction() const;

        /// \return the whole URL for this part
        const PatternURL &GetURL() const;

    private:

        std::string part;

        PatternURL url;

        functionProcess fnc;

        std::unordered_map<_internal::RegexPart, std::shared_ptr<URLPart>> descendants;

        // TODO: implement more regex parts of an url and be able to search in them
        std::vector<std::pair<_internal::RegexPart, std::shared_ptr<URLPart>>> regexDescendants;
    };

    /// Class for maintaining the hierarchy URL tree
    class URLMapper {
    public:
        /// Basic constructor
        URLMapper();

        ~URLMapper() = default;

        /// Register a new mapped URL with the process function
        /// \param uri the URI as a string
        /// \param _fnc the process fucntion
        void RegisterURL(const std::string &uri, functionProcess _fnc);

        /// \param uri the URL
        /// \return if that URL is mapped
        /// \throws HTTPException::HTTPNotFound if the URL is not mapped
        std::pair<functionProcess, URL> FindURL(URL &uri);

        /// \param uri the string of the URL
        /// \return if that URL is mapped
        /// \throws HTTPException::HTTPNotFound if the URL is not mapped
        std::pair<functionProcess, URL> FindURL(const std::string &uri);


    private:

        std::shared_ptr<URLPart> root;


    };
}

#endif //CPP_WEB_SERVER_URLMAPPER_H
