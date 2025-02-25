#ifndef CPP_WEB_SERVER_SERVERERROR_H
#define CPP_WEB_SERVER_SERVERERROR_H

#include <HTTPResolver/Exceptions/HTTPExceptionBase.h>

namespace HTTPException {
    /// Internal Server Error
    /// Error code: 500
    class HTTPInternalServerError: public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPInternalServerError(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(ErrorCode::InternalServerError,
                                                                                                 "InternalServerError", _webSite,
                                                                                                 _site) {}
    };
    /// Not Implemented
    /// Error code: 501
    class HTTPNotImplemented : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPNotImplemented(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(ErrorCode::NotImplemented,
                                                                                                 "NotImplemented", _webSite,
                                                                                                 _site) {}
    };
    /// Bad Gateway
    /// Error code: 502
    class HTTPBadGateway : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPBadGateway(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(ErrorCode::BadGateway,
                                                                                                 "BadGateway", _webSite,
                                                                                                 _site) {}
    };
    /// Service Unavailable
    /// Error code: 503
    class HTTPServiceUnavailable : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPServiceUnavailable(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(ErrorCode::ServiceUnavailable,
                                                                                                 "ServiceUnavailable", _webSite,
                                                                                                 _site) {}
    };
    /// Gateway Timeout
    /// Error code: 504
    class HTTPGatewayTimeout: public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPGatewayTimeout(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(ErrorCode::GatewayTimeout,
                                                                                                 "GatewayTimeout", _webSite,
                                                                                                 _site) {}
    };
    /// HTTP Version Not Supported
    /// Error code: 505
    class HTTPHTTPVersionNotSupported : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPHTTPVersionNotSupported(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(ErrorCode::HTTPVersionNotSupported,
                                                                                                 "HTTPVersionNotSupported", _webSite,
                                                                                                 _site) {}
    };
    /// Variant Also Negotiates
    /// Error code: 506
    class HTTPVariantAlsoNegotiates: public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPVariantAlsoNegotiates(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(ErrorCode::VariantAlsoNegotiates,
                                                                                                 "VariantAlsoNegotiates", _webSite,
                                                                                                 _site) {}
    };
    /// Insufficient Storage
    /// Error code: 507
    class HTTPInsufficientStorage: public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPInsufficientStorage(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(ErrorCode::InsufficientStorage,
                                                                                                 "InsufficientStorage", _webSite,
                                                                                                 _site) {}
    };
    /// Loop Detected
    /// Error code: 508
    class HTTPLoopDetected : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPLoopDetected(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(ErrorCode::LoopDetected,
                                                                                                 "LoopDetected", _webSite,
                                                                                                 _site) {}
    };
    /// Not Extended
    /// Error code: 510
    class HTTPNotExtended : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPNotExtended(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(ErrorCode::NotExtended,
                                                                                                 "NotExtended", _webSite,
                                                                                                 _site) {}
    };
    /// Network Authentication Required
    /// Error code: 511
    class HTTPNetworkAuthenticationRequired : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPNetworkAuthenticationRequired(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(ErrorCode::NetworkAuthenticationRequired,
                                                                                                  "NetworkAuthenticationRequired", _webSite,
                                                                                                  _site) {}
    };
}

#endif //CPP_WEB_SERVER_SERVERERROR_H
