#ifndef CPP_WEB_SERVER_CLIENTERROR_H
#define CPP_WEB_SERVER_CLIENTERROR_H

#include <HTTPResolver/Exceptions/HTTPExceptionBase.h>

namespace ws::HTTPException {
    /// HTTP Bad Request
    /// Error code: 400
    class HTTPBadRequest : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPBadRequest(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(ErrorCode::BadRequest,
                                                                                                 "BadRequest", _webSite,
                                                                                                 _site) {}
    };

    /// HTTP Unauthorized
    /// Error code: 401
    class HTTPUnauthorized : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPUnauthorized(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(
                ErrorCode::Unauthorized, "Unauthorized", _webSite, _site) {}
    };

    /// HTTP Payment Required
    /// Error code: 402
    class HTTPPaymentRequired : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPPaymentRequired(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(
                ErrorCode::PaymentRequired, "PaymentRequired", _webSite, _site) {}
    };

    /// HTTP Forbidden
    /// Error code: 403
    class HTTPForbidden : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPForbidden(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(ErrorCode::Forbidden,
                                                                                                "Forbidden", _webSite,
                                                                                                _site) {}
    };

    /// HTTP Not Found
    /// Error code: 404
    class HTTPNotFound : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPNotFound(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(ErrorCode::NotFound,
                                                                                               "NotFound", _webSite,
                                                                                               _site) {}
    };

    /// HTTP Method Not Allowed
    /// Error code: 405
    class HTTPMethodNotAllowed : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPMethodNotAllowed(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(
                ErrorCode::MethodNotAllowed, "MethodNotAllowed", _webSite, _site) {}
    };

    /// HTTP Not Acceptable
    /// Error code: 406
    class HTTPNotAcceptable : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPNotAcceptable(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(
                ErrorCode::NotAcceptable, "NotAcceptable", _webSite, _site) {}
    };

    /// HTTP Proxy Authentication Required
    /// Error code: 407
    class HTTPProxyAuthenticationRequired : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPProxyAuthenticationRequired(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(
                ErrorCode::ProxyAuthenticationRequired, "ProxyAuthenticationRequired", _webSite, _site) {}
    };

    /// HTTP Request Timeout
    /// Error code: 408
    class HTTPRequestTimeout : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPRequestTimeout(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(
                ErrorCode::RequestTimeout, "RequestTimeout", _webSite, _site) {}
    };

    /// HTTP Conflict
    /// Error code: 409
    class HTTPConflict : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPConflict(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(ErrorCode::Conflict,
                                                                                               "Conflict", _webSite,
                                                                                               _site) {}
    };

    /// HTTP Gone
    /// Error code: 410
    class HTTPGone : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPGone(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(ErrorCode::Gone, "Gone",
                                                                                           _webSite, _site) {}
    };

    /// HTTP Length Required
    /// Error code: 411
    class HTTPLengthRequired : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPLengthRequired(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(
                ErrorCode::LengthRequired, "LengthRequired", _webSite, _site) {}
    };

    /// HTTP Precondition Failed
    /// Error code: 412
    class HTTPPreconditionFailed : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPPreconditionFailed(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(
                ErrorCode::PreconditionFailed, "PreconditionFailed", _webSite, _site) {}
    };

    /// HTTP Payload Too Large
    /// Error code: 413
    class HTTPPayloadTooLarge : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPPayloadTooLarge(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(
                ErrorCode::PayloadTooLarge, "PayloadTooLarge", _webSite, _site) {}
    };

    /// HTTP URI Too Long
    /// Error code: 414
    class HTTPURITooLong : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPURITooLong(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(ErrorCode::URITooLong,
                                                                                                 "URITooLong", _webSite,
                                                                                                 _site) {}
    };

    /// HTTP Unsupported Media Type
    /// Error code: 415
    class HTTPUnsupportedMediaType : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPUnsupportedMediaType(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(
                ErrorCode::UnsupportedMediaType, "UnsupportedMediaType", _webSite, _site) {}
    };

    /// HTTP Range Not Satisfiable
    /// Error code: 416
    class HTTPRangeNotSatisfiable : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPRangeNotSatisfiable(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(
                ErrorCode::RangeNotSatisfiable, "RangeNotSatisfiable", _webSite, _site) {}
    };

    /// HTTP Expectation Failed
    /// Error code: 417
    class HTTPExpectationFailed : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPExpectationFailed(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(
                ErrorCode::ExpectationFailed, "ExpectationFailed", _webSite, _site) {}
    };

    /// HTTP Misdirected Request
    /// Error code: 421
    class HTTPMisdirectedRequest : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPMisdirectedRequest(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(
                ErrorCode::MisdirectedRequest, "MisdirectedRequest", _webSite, _site) {}
    };

    /// HTTP Unprocessable Entity
    /// Error code: 422
    class HTTPUnprocessableEntity : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPUnprocessableEntity(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(
                ErrorCode::UnprocessableEntity, "UnprocessableEntity", _webSite, _site) {}
    };

    /// HTTP Locked
    /// Error code: 423
    class HTTPLocked : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPLocked(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(ErrorCode::Locked,
                                                                                             "Locked", _webSite,
                                                                                             _site) {}
    };

    /// HTTP Failed Dependency
    /// Error code: 424
    class HTTPFailedDependency : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPFailedDependency(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(
                ErrorCode::FailedDependency, "FailedDependency", _webSite, _site) {}
    };

    /// HTTP Too Early
    /// Error code: 425
    class HTTPTooEarly : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPTooEarly(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(ErrorCode::TooEarly,
                                                                                               "TooEarly", _webSite,
                                                                                               _site) {}
    };

    /// HTTP Upgrade Required
    /// Error code: 526
    class HTTPUpgradeRequired : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPUpgradeRequired(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(
                ErrorCode::UpgradeRequired, "UpgradeRequired", _webSite, _site) {}
    };

    /// HTTP Precondition Required
    /// Error code: 428
    class HTTPPreconditionRequired : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPPreconditionRequired(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(
                ErrorCode::PreconditionRequired, "PreconditionRequired", _webSite, _site) {}
    };

    /// HTTP Too Many Request
    /// Error code: 429
    class HTTPTooManyRequest : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPTooManyRequest(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(
                ErrorCode::TooManyRequest, "TooManyRequest", _webSite, _site) {}
    };

    /// HTTP Request Header Field Too Large
    /// Error code: 431
    class HTTPRequestHeaderFieldTooLarge : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPRequestHeaderFieldTooLarge(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(
                ErrorCode::RequestHeaderFieldTooLarge, "RequestHeaderFieldTooLarge", _webSite, _site) {}
    };

    /// HTTP Unavailable For Legal Reasons
    /// Error code: 451
    class HTTPUnavailableForLegalReasons : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPUnavailableForLegalReasons(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(
                ErrorCode::UnavailableForLegalReasons, "UnavailableForLegalReasons", _webSite, _site) {}
    };
}

#endif //CPP_WEB_SERVER_CLIENTERROR_H
