#ifndef CPP_WEB_SERVER_PATTERNURL_H
#define CPP_WEB_SERVER_PATTERNURL_H

#include <string>
#include <unordered_map>

#include <Logger.h>
#include <URL/URL.h>

namespace ws::url {

    /// Class for storing a URL with regex support
    class PatternURL : public URL {
    public:

        /// URL as a string
        /// Supports creating URLs with names for regex parameters in the format: /part/{regex-part}
        /// \param _uri URL as a string
        PatternURL(const std::string &_uri);

        ~PatternURL() override = default;

        /// Compares basic URL with this regex supported URL, setts regex parts to the URL [key][value]
        /// key is the name from the URL in {}
        /// value is the mapped value corresponding that regex
        /// \param other other URL to compare with
        /// \return if the URL is mapped on this regex URL
        bool operator==(URL &other) override;

        /// Compares basic URL with this regex supported URL
        /// \param otherUri uri to compare with
        /// \return if the uri is mapped on this regex URL
        bool operator==(std::string &otherUri) override;

        /// Compares basic URL with this regex supported URL
        /// \param otherUri uri to compare with
        /// \return if the uri is mapped on this regex URL
        bool operator==(const std::string &otherUri) override;

        /// Prints the content of this regex URL
        void Print();

    private:

        std::string RegexUriBase;
        std::regex RegexUri;

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
        std::regex words = std::regex("\\{?[[:alnum:]]+\\}?", flags);
        std::regex uriPattern = std::regex("\\{[[:alnum:]]+\\}", flags);
        std::regex replacePatter = std::regex("[[:alnum:]]+", flags);
        std::string replacePatterString = "[[:alnum:]]+";

        std::unordered_map<int, std::string> dynamicURLMapping;

    };

} // namespace ws::url

#endif //CPP_WEB_SERVER_PATTERNURL_H
