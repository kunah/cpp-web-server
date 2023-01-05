#include <WebServer.h>
#include <HTTPMappingRegistrar.h>

REGISTER_URI(HTTPMethod::GET, "/", "dist/index.html", "text/html")
REGISTER_URI(HTTPMethod::GET, "/about", "dist/about.html", "text/html")
REGISTER_URI(HTTPMethod::GET, "/favicon.ico", "dist/favicon.ico", "image/x-icon")
REGISTER_URI(HTTPMethod::GET, "/face.jpg", "dist/face.jpg", "image/jpg")

int main() {

//    std::vector<std::string> errors = {    "BadRequest" ,
//            "Unauthorized",
//            "PaymentRequired",
//            "Forbidden",
//            "NotFound",
//            "MethodNotAllowed",
//            "NotAcceptable",
//            "ProxyAuthenticationRequired",
//            "RequestTimeout",
//            "Conflict",
//            "Gone",
//            "LengthRequired",
//            "PreconditionFailed",
//            "PayloadTooLarge",
//            "URITooLong",
//            "UnsupportedMediaType",
//            "RangeNotSatisfiable",
//            "ExpectationFailed",
//            "MisdirectedRequest",
//            "UnprocessableEntity",
//            "Locked",
//            "FailedDependency",
//            "TooEarly",
//            "UpgradeRequired",
//            "PreconditionRequired",
//            "TooManyRequest",
//            "RequestHeaderFieldTooLarge",
//            "UnavailableForLegalReasons"};
//
//    for(auto & er : errors){
//        std::cout << "class HTTP" << er << " : public ClientError {\n"
//                     << "public:\n"
//                     << "    HTTP"<< er << "( bool _webSite = false, const std::string & _site = \"\")"
//                     << " : ClientError(ClientErrorCode::"<<er<<", \"" << er <<"\", _webSite, _site) {}\n"
//                     << "};\n" << std::endl;
//    }

    WebServer(8080).Run();
//    WebServer(8000).Run();
    return 0;
}
