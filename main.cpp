#include <WebServer.h>
#include <HTTPMappingRegistrar.h>

REGISTER_URI(HTTPMethod::GET, "/", "dist/index.html", "text/html")
REGISTER_URI(HTTPMethod::GET, "/about", "dist/about.html", "text/html")
REGISTER_URI(HTTPMethod::GET, "/favicon.ico", "dist/favicon.ico", "image/x-icon")
REGISTER_URI(HTTPMethod::GET, "/face.jpg", "dist/face.jpg", "image/jpg")

int main() {

    WebServer(8080).Run();
//    WebServer(8000).Run();
    return 0;
}
