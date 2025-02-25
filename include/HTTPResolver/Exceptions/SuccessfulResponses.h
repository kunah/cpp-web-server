#ifndef CPP_WEB_SERVER_SUCCESSFULREPONSES_H
#define CPP_WEB_SERVER_SUCCESSFULREPONSES_H

#include <HTTPResolver/Exceptions/HTTPExceptionBase.h>

namespace HTTPException {
    /// OK
    /// Error code: 200
    class HTTPOK : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPOK(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(
                ErrorCode::OK,
                "OK", _webSite,
                _site) {}
    };

    /// Created
    /// Error code: 201
    class HTTPCreated : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPCreated(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(
                ErrorCode::Created,
                "Created", _webSite,
                _site) {}
    };

    /// Accepted
    /// Error code: 202
    class HTTPAccepted : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPAccepted(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(ErrorCode::Accepted,
                                                                                            "Accepted", _webSite,
                                                                                            _site) {}
    };

    /// Non-Authoritative Information
    /// Error code: 203
    class HTTPNonAuthoritativeInformation : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPNonAuthoritativeInformation(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(
                ErrorCode::NonAuthoritativeInformation,
                "NonAuthoritativeInformation", _webSite,
                _site) {}
    };

    /// No Content
    /// Error code: 204
    class HTTPNoContent : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPNoContent(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(
                ErrorCode::NoContent,
                "NoContent", _webSite,
                _site) {}
    };

    /// Reset Content
    /// Error code: 205
    class HTTPResetContent : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPResetContent(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(
                ErrorCode::ResetContent,
                "ResetContent", _webSite,
                _site) {}
    };

    /// Partial Content
    /// Error code: 206
    class HTTPPartialContent : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPPartialContent(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(
                ErrorCode::PartialContent,
                "PartialContent", _webSite,
                _site) {}
    };

    /// Multi-Status
    /// Error code: 207
    class HTTPMultiStatus : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPMultiStatus(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(
                ErrorCode::MultiStatus,
                "MultiStatus", _webSite,
                _site) {}
    };

    /// Already Reported
    /// Error code: 208
    class HTTPAlreadyReported : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPAlreadyReported(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(
                ErrorCode::AlreadyReported,
                "AlreadyReported", _webSite,
                _site) {}
    };

    /// IM Used
    /// Error code: 208
    class HTTPIMUsed : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPIMUsed(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(
                ErrorCode::IMUsed,
                "IMUsed", _webSite,
                _site) {}
    };

}

#endif //CPP_WEB_SERVER_SUCCESSFULREPONSES_H
