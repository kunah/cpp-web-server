#ifndef CPP_WEB_SERVER_CLIENTERROR_H
#define CPP_WEB_SERVER_CLIENTERROR_H

#include <Exceptions/HTTPExceptionBase.h>

namespace HTTPException{

    class HTTPBadRequest : public HTTPExceptionBase {
    public:
        HTTPBadRequest( bool _webSite = false, const std::string & _site = "") : HTTPExceptionBase(ErrorCode::BadRequest, "BadRequest", _webSite, _site) {}
    };

    class HTTPUnauthorized : public HTTPExceptionBase {
    public:
        HTTPUnauthorized( bool _webSite = false, const std::string & _site = "") : HTTPExceptionBase(ErrorCode::Unauthorized, "Unauthorized", _webSite, _site) {}
    };

    class HTTPPaymentRequired : public HTTPExceptionBase {
    public:
        HTTPPaymentRequired( bool _webSite = false, const std::string & _site = "") : HTTPExceptionBase(ErrorCode::PaymentRequired, "PaymentRequired", _webSite, _site) {}
    };

    class HTTPForbidden : public HTTPExceptionBase {
    public:
        HTTPForbidden( bool _webSite = false, const std::string & _site = "") : HTTPExceptionBase(ErrorCode::Forbidden, "Forbidden", _webSite, _site) {}
    };

    class HTTPNotFound : public HTTPExceptionBase {
    public:
        HTTPNotFound( bool _webSite = false, const std::string & _site = "") : HTTPExceptionBase(ErrorCode::NotFound, "NotFound", _webSite, _site) {}
    };

    class HTTPMethodNotAllowed : public HTTPExceptionBase {
    public:
        HTTPMethodNotAllowed( bool _webSite = false, const std::string & _site = "") : HTTPExceptionBase(ErrorCode::MethodNotAllowed, "MethodNotAllowed", _webSite, _site) {}
    };

    class HTTPNotAcceptable : public HTTPExceptionBase {
    public:
        HTTPNotAcceptable( bool _webSite = false, const std::string & _site = "") : HTTPExceptionBase(ErrorCode::NotAcceptable, "NotAcceptable", _webSite, _site) {}
    };

    class HTTPProxyAuthenticationRequired : public HTTPExceptionBase {
    public:
        HTTPProxyAuthenticationRequired( bool _webSite = false, const std::string & _site = "") : HTTPExceptionBase(ErrorCode::ProxyAuthenticationRequired, "ProxyAuthenticationRequired", _webSite, _site) {}
    };

    class HTTPRequestTimeout : public HTTPExceptionBase {
    public:
        HTTPRequestTimeout( bool _webSite = false, const std::string & _site = "") : HTTPExceptionBase(ErrorCode::RequestTimeout, "RequestTimeout", _webSite, _site) {}
    };

    class HTTPConflict : public HTTPExceptionBase {
    public:
        HTTPConflict( bool _webSite = false, const std::string & _site = "") : HTTPExceptionBase(ErrorCode::Conflict, "Conflict", _webSite, _site) {}
    };

    class HTTPGone : public HTTPExceptionBase {
    public:
        HTTPGone( bool _webSite = false, const std::string & _site = "") : HTTPExceptionBase(ErrorCode::Gone, "Gone", _webSite, _site) {}
    };

    class HTTPLengthRequired : public HTTPExceptionBase {
    public:
        HTTPLengthRequired( bool _webSite = false, const std::string & _site = "") : HTTPExceptionBase(ErrorCode::LengthRequired, "LengthRequired", _webSite, _site) {}
    };

    class HTTPPreconditionFailed : public HTTPExceptionBase {
    public:
        HTTPPreconditionFailed( bool _webSite = false, const std::string & _site = "") : HTTPExceptionBase(ErrorCode::PreconditionFailed, "PreconditionFailed", _webSite, _site) {}
    };

    class HTTPPayloadTooLarge : public HTTPExceptionBase {
    public:
        HTTPPayloadTooLarge( bool _webSite = false, const std::string & _site = "") : HTTPExceptionBase(ErrorCode::PayloadTooLarge, "PayloadTooLarge", _webSite, _site) {}
    };

    class HTTPURITooLong : public HTTPExceptionBase {
    public:
        HTTPURITooLong( bool _webSite = false, const std::string & _site = "") : HTTPExceptionBase(ErrorCode::URITooLong, "URITooLong", _webSite, _site) {}
    };

    class HTTPUnsupportedMediaType : public HTTPExceptionBase {
    public:
        HTTPUnsupportedMediaType( bool _webSite = false, const std::string & _site = "") : HTTPExceptionBase(ErrorCode::UnsupportedMediaType, "UnsupportedMediaType", _webSite, _site) {}
    };

    class HTTPRangeNotSatisfiable : public HTTPExceptionBase {
    public:
        HTTPRangeNotSatisfiable( bool _webSite = false, const std::string & _site = "") : HTTPExceptionBase(ErrorCode::RangeNotSatisfiable, "RangeNotSatisfiable", _webSite, _site) {}
    };

    class HTTPExpectationFailed : public HTTPExceptionBase {
    public:
        HTTPExpectationFailed( bool _webSite = false, const std::string & _site = "") : HTTPExceptionBase(ErrorCode::ExpectationFailed, "ExpectationFailed", _webSite, _site) {}
    };

    class HTTPMisdirectedRequest : public HTTPExceptionBase {
    public:
        HTTPMisdirectedRequest( bool _webSite = false, const std::string & _site = "") : HTTPExceptionBase(ErrorCode::MisdirectedRequest, "MisdirectedRequest", _webSite, _site) {}
    };

    class HTTPUnprocessableEntity : public HTTPExceptionBase {
    public:
        HTTPUnprocessableEntity( bool _webSite = false, const std::string & _site = "") : HTTPExceptionBase(ErrorCode::UnprocessableEntity, "UnprocessableEntity", _webSite, _site) {}
    };

    class HTTPLocked : public HTTPExceptionBase {
    public:
        HTTPLocked( bool _webSite = false, const std::string & _site = "") : HTTPExceptionBase(ErrorCode::Locked, "Locked", _webSite, _site) {}
    };

    class HTTPFailedDependency : public HTTPExceptionBase {
    public:
        HTTPFailedDependency( bool _webSite = false, const std::string & _site = "") : HTTPExceptionBase(ErrorCode::FailedDependency, "FailedDependency", _webSite, _site) {}
    };

    class HTTPTooEarly : public HTTPExceptionBase {
    public:
        HTTPTooEarly( bool _webSite = false, const std::string & _site = "") : HTTPExceptionBase(ErrorCode::TooEarly, "TooEarly", _webSite, _site) {}
    };

    class HTTPUpgradeRequired : public HTTPExceptionBase {
    public:
        HTTPUpgradeRequired( bool _webSite = false, const std::string & _site = "") : HTTPExceptionBase(ErrorCode::UpgradeRequired, "UpgradeRequired", _webSite, _site) {}
    };

    class HTTPPreconditionRequired : public HTTPExceptionBase {
    public:
        HTTPPreconditionRequired( bool _webSite = false, const std::string & _site = "") : HTTPExceptionBase(ErrorCode::PreconditionRequired, "PreconditionRequired", _webSite, _site) {}
    };

    class HTTPTooManyRequest : public HTTPExceptionBase {
    public:
        HTTPTooManyRequest( bool _webSite = false, const std::string & _site = "") : HTTPExceptionBase(ErrorCode::TooManyRequest, "TooManyRequest", _webSite, _site) {}
    };

    class HTTPRequestHeaderFieldTooLarge : public HTTPExceptionBase {
    public:
        HTTPRequestHeaderFieldTooLarge( bool _webSite = false, const std::string & _site = "") : HTTPExceptionBase(ErrorCode::RequestHeaderFieldTooLarge, "RequestHeaderFieldTooLarge", _webSite, _site) {}
    };

    class HTTPUnavailableForLegalReasons : public HTTPExceptionBase {
    public:
        HTTPUnavailableForLegalReasons( bool _webSite = false, const std::string & _site = "") : HTTPExceptionBase(ErrorCode::UnavailableForLegalReasons, "UnavailableForLegalReasons", _webSite, _site) {}
    };
}

#endif //CPP_WEB_SERVER_CLIENTERROR_H
