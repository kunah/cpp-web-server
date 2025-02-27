#ifndef CPP_WEB_SERVER_REDIRECTIONMESSAGES_H
#define CPP_WEB_SERVER_REDIRECTIONMESSAGES_H

#include <HTTPResolver/Exceptions/HTTPExceptionBase.h>

namespace ws::HTTPException {
    /// Multiple Choices
    /// Error code: 300
    class HTTPMultipleChoices : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPMultipleChoices(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(
                ErrorCode::MultipleChoices,
                "MultipleChoices", _webSite,
                _site) {}
    };

    /// Moved Permanently
    /// Error code: 301
    class HTTPMovedPermanently : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPMovedPermanently(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(
                ErrorCode::MovedPermanently,
                "MovedPermanently", _webSite,
                _site) {}
    };

    /// Found
    /// Error code: 302
    class HTTPFound : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPFound(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(ErrorCode::Found,
                                                                                                 "Found", _webSite,
                                                                                                 _site) {}
    };

    /// See Other
    /// Error code: 303
    class HTTPSeeOther : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPSeeOther(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(
                ErrorCode::SeeOther,
                "SeeOther", _webSite,
                _site) {}
    };

    /// Not Modified
    /// Error code: 304
    class HTTPNotModified : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPNotModified(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(
                ErrorCode::NotModified,
                "NotModified", _webSite,
                _site) {}
    };

    /// Use Proxy
    /// Error code: 305
    class HTTPUseProxy : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPUseProxy(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(
                ErrorCode::UseProxy,
                "UseProxy", _webSite,
                _site) {}
    };

    /// unused
    /// Error code: 306
    class HTTPunused : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPunused(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(
                ErrorCode::unused,
                "unused", _webSite,
                _site) {}
    };

    /// Temporary Redirect
    /// Error code: 307
    class HTTPTemporaryRedirect : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPTemporaryRedirect(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(
                ErrorCode::TemporaryRedirect,
                "TemporaryRedirect", _webSite,
                _site) {}
    };

    /// Permanent Redirect
    /// Error code: 308
    class HTTPPermanentRedirect : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPPermanentRedirect(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(
                ErrorCode::PermanentRedirect,
                "PermanentRedirect", _webSite,
                _site) {}
    };

} // namespace ws::HTTPException

#endif //CPP_WEB_SERVER_REDIRECTIONMESSAGES_H
