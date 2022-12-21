#ifndef CPP_WEB_SERVER_HTTPEXCEPTIONBASE_H
#define CPP_WEB_SERVER_HTTPEXCEPTIONBASE_H

#include <string>
#include <fstream>
#include <exception>

#include <Logger.h>
#include <HTTPParser.h>


namespace HTTPException{

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

    class HTTPExceptionBase : public std::exception{
        public:
            HTTPExceptionBase( ErrorCode _code, const std::string & _msg, bool _webSite, const std::string & _site);

            HTTPParser Response();
        private:
            ErrorCode code;
            bool webSite;
            std::string site;
            std::string msg;
    };


}
#endif //CPP_WEB_SERVER_HTTPEXCEPTIONBASE_H
