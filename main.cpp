#include <WebServer.h>

int main() {

    std::vector<std::string> errors = {    "BadRequest" ,
            "Unauthorized",
            "PaymentRequired",
            "Forbidden",
            "NotFound",
            "MethodNotAllowed",
            "NotAcceptable",
            "ProxyAuthenticationRequired",
            "RequestTimeout",
            "Conflict",
            "Gone",
            "LengthRequired",
            "PreconditionFailed",
            "PayloadTooLarge",
            "URITooLong",
            "UnsupportedMediaType",
            "RangeNotSatisfiable",
            "ExpectationFailed",
            "MisdirectedRequest",
            "UnprocessableEntity",
            "Locked",
            "FailedDependency",
            "TooEarly",
            "UpgradeRequired",
            "PreconditionRequired",
            "TooManyRequest",
            "RequestHeaderFieldTooLarge",
            "UnavailableForLegalReasons"};

    for(auto & er : errors){
        std::cout << "class HTTP" << er << " : public ClientError {\n"
                     << "public:\n"
                     << "    HTTP"<< er << "( bool _webSite = false, const std::string & _site = \"\")"
                     << " : ClientError(ClientErrorCode::"<<er<<", _webSite, _site) {}\n"
                     << "};\n" << std::endl;
    }

//    WebServer(8080).Run();
    return 0;
}
