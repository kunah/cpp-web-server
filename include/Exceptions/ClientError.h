#ifndef CPP_WEB_SERVER_CLIENTERROR_H
#define CPP_WEB_SERVER_CLIENTERROR_H

#include <exception>
#include <sstream>
#include <string>
#include <HTTPParser.h>

#include <Logger.h>

namespace HTTPError{

    enum ClientErrorCode{
        BadRequest = 400,
        Unauthorized,
        PaymentRequired,
        Forbidden,
        NotFound,
        MethodNotAllowed,
        NotAcceptable,
        ProxyAuthenticationRequired,
        RequestTimeout,
        Conflict,
        Gone,
        LengthRequired,
        PreconditionFailed,
        PayloadTooLarge,
        URITooLong,
        UnsupportedMediaType,
        RangeNotSatisfiable,
        ExpectationFailed,
        MisdirectedRequest = 421,
        UnprocessableEntity,
        Locked,
        FailedDependency,
        TooEarly,
        UpgradeRequired,
        PreconditionRequired = 428,
        TooManyRequest,
        RequestHeaderFieldTooLarge = 431,
        UnavailableForLegalReasons = 451

    };

    class ClientError : public std::exception {
    public:
        ClientError( ClientErrorCode _code, bool _webSite, const std::string & _site);

        std::string Response();
    private:
        ClientErrorCode code;
        bool webSite;
        std::string site;
    };

    class HTTPBadRequest : public ClientError {
    public:
        HTTPBadRequest( bool _webSite = false, const std::string & _site = "") : ClientError(ClientErrorCode::BadRequest, _webSite, _site) {}
    };

    class HTTPUnauthorized : public ClientError {
    public:
        HTTPUnauthorized( bool _webSite = false, const std::string & _site = "") : ClientError(ClientErrorCode::Unauthorized, _webSite, _site) {}
    };

    class HTTPPaymentRequired : public ClientError {
    public:
        HTTPPaymentRequired( bool _webSite = false, const std::string & _site = "") : ClientError(ClientErrorCode::PaymentRequired, _webSite, _site) {}
    };

    class HTTPForbidden : public ClientError {
    public:
        HTTPForbidden( bool _webSite = false, const std::string & _site = "") : ClientError(ClientErrorCode::Forbidden, _webSite, _site) {}
    };

    class HTTPNotFound : public ClientError {
    public:
        HTTPNotFound( bool _webSite = false, const std::string & _site = "") : ClientError(ClientErrorCode::NotFound, _webSite, _site) {}
    };

    class HTTPMethodNotAllowed : public ClientError {
    public:
        HTTPMethodNotAllowed( bool _webSite = false, const std::string & _site = "") : ClientError(ClientErrorCode::MethodNotAllowed, _webSite, _site) {}
    };

    class HTTPNotAcceptable : public ClientError {
    public:
        HTTPNotAcceptable( bool _webSite = false, const std::string & _site = "") : ClientError(ClientErrorCode::NotAcceptable, _webSite, _site) {}
    };

    class HTTPProxyAuthenticationRequired : public ClientError {
    public:
        HTTPProxyAuthenticationRequired( bool _webSite = false, const std::string & _site = "") : ClientError(ClientErrorCode::ProxyAuthenticationRequired, _webSite, _site) {}
    };

    class HTTPRequestTimeout : public ClientError {
    public:
        HTTPRequestTimeout( bool _webSite = false, const std::string & _site = "") : ClientError(ClientErrorCode::RequestTimeout, _webSite, _site) {}
    };

    class HTTPConflict : public ClientError {
    public:
        HTTPConflict( bool _webSite = false, const std::string & _site = "") : ClientError(ClientErrorCode::Conflict, _webSite, _site) {}
    };

    class HTTPGone : public ClientError {
    public:
        HTTPGone( bool _webSite = false, const std::string & _site = "") : ClientError(ClientErrorCode::Gone, _webSite, _site) {}
    };

    class HTTPLengthRequired : public ClientError {
    public:
        HTTPLengthRequired( bool _webSite = false, const std::string & _site = "") : ClientError(ClientErrorCode::LengthRequired, _webSite, _site) {}
    };

    class HTTPPreconditionFailed : public ClientError {
    public:
        HTTPPreconditionFailed( bool _webSite = false, const std::string & _site = "") : ClientError(ClientErrorCode::PreconditionFailed, _webSite, _site) {}
    };

    class HTTPPayloadTooLarge : public ClientError {
    public:
        HTTPPayloadTooLarge( bool _webSite = false, const std::string & _site = "") : ClientError(ClientErrorCode::PayloadTooLarge, _webSite, _site) {}
    };

    class HTTPURITooLong : public ClientError {
    public:
        HTTPURITooLong( bool _webSite = false, const std::string & _site = "") : ClientError(ClientErrorCode::URITooLong, _webSite, _site) {}
    };

    class HTTPUnsupportedMediaType : public ClientError {
    public:
        HTTPUnsupportedMediaType( bool _webSite = false, const std::string & _site = "") : ClientError(ClientErrorCode::UnsupportedMediaType, _webSite, _site) {}
    };

    class HTTPRangeNotSatisfiable : public ClientError {
    public:
        HTTPRangeNotSatisfiable( bool _webSite = false, const std::string & _site = "") : ClientError(ClientErrorCode::RangeNotSatisfiable, _webSite, _site) {}
    };

    class HTTPExpectationFailed : public ClientError {
    public:
        HTTPExpectationFailed( bool _webSite = false, const std::string & _site = "") : ClientError(ClientErrorCode::ExpectationFailed, _webSite, _site) {}
    };

    class HTTPMisdirectedRequest : public ClientError {
    public:
        HTTPMisdirectedRequest( bool _webSite = false, const std::string & _site = "") : ClientError(ClientErrorCode::MisdirectedRequest, _webSite, _site) {}
    };

    class HTTPUnprocessableEntity : public ClientError {
    public:
        HTTPUnprocessableEntity( bool _webSite = false, const std::string & _site = "") : ClientError(ClientErrorCode::UnprocessableEntity, _webSite, _site) {}
    };

    class HTTPLocked : public ClientError {
    public:
        HTTPLocked( bool _webSite = false, const std::string & _site = "") : ClientError(ClientErrorCode::Locked, _webSite, _site) {}
    };

    class HTTPFailedDependency : public ClientError {
    public:
        HTTPFailedDependency( bool _webSite = false, const std::string & _site = "") : ClientError(ClientErrorCode::FailedDependency, _webSite, _site) {}
    };

    class HTTPTooEarly : public ClientError {
    public:
        HTTPTooEarly( bool _webSite = false, const std::string & _site = "") : ClientError(ClientErrorCode::TooEarly, _webSite, _site) {}
    };

    class HTTPUpgradeRequired : public ClientError {
    public:
        HTTPUpgradeRequired( bool _webSite = false, const std::string & _site = "") : ClientError(ClientErrorCode::UpgradeRequired, _webSite, _site) {}
    };

    class HTTPPreconditionRequired : public ClientError {
    public:
        HTTPPreconditionRequired( bool _webSite = false, const std::string & _site = "") : ClientError(ClientErrorCode::PreconditionRequired, _webSite, _site) {}
    };

    class HTTPTooManyRequest : public ClientError {
    public:
        HTTPTooManyRequest( bool _webSite = false, const std::string & _site = "") : ClientError(ClientErrorCode::TooManyRequest, _webSite, _site) {}
    };

    class HTTPRequestHeaderFieldTooLarge : public ClientError {
    public:
        HTTPRequestHeaderFieldTooLarge( bool _webSite = false, const std::string & _site = "") : ClientError(ClientErrorCode::RequestHeaderFieldTooLarge, _webSite, _site) {}
    };

    class HTTPUnavailableForLegalReasons : public ClientError {
    public:
        HTTPUnavailableForLegalReasons( bool _webSite = false, const std::string & _site = "") : ClientError(ClientErrorCode::UnavailableForLegalReasons, _webSite, _site) {}
    };

}

#endif //CPP_WEB_SERVER_CLIENTERROR_H
