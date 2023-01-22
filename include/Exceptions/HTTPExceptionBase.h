#ifndef CPP_WEB_SERVER_HTTPEXCEPTIONBASE_H
#define CPP_WEB_SERVER_HTTPEXCEPTIONBASE_H

#include <string>
#include <fstream>
#include <exception>

#include <Logger.h>
#include <HTTPParser.h>


namespace HTTPException{

    /// Enum of every single implemented error code exception for HTTP
    enum ErrorCode{
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

    /// Base exception interface for HTTP server
    class HTTPExceptionBase : public std::exception{
        public:
            /// \param _code HTTP error code
            /// \param _msg msg of the exception
            /// \param _webSite if to send a web site back
            /// \param _site path to the site
            HTTPExceptionBase( ErrorCode _code, std::string _msg, bool _webSite, std::string  _site);

            /// Generates response with given values
            HTTPParser Response();
        private:
            ErrorCode code;
            bool webSite;
            std::string site;
            std::string msg;
    };


}
#endif //CPP_WEB_SERVER_HTTPEXCEPTIONBASE_H
