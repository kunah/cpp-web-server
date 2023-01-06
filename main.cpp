#include <WebServer.h>
#include <HTTPMappingRegistrar.h>
#include <ProcessClasses/HTTPTextProcess.h>
#include <ProcessClasses/HTTPBinaryProcess.h>

// TODO: solve error -> malloc: Heap corruption detected, free list is damaged at ....

REGISTER_URI(HTTPMethod::GET, "/", HTTPTextProcess, "dist/index.html", "text/html")
REGISTER_URI(HTTPMethod::GET, "/about", HTTPTextProcess, "dist/about.html", "text/html")
REGISTER_URI(HTTPMethod::GET, "/favicon.ico", HTTPBinaryProcess   , "dist/favicon.ico", "image/x-icon", 60)
REGISTER_URI(HTTPMethod::GET, "/face.jpg", HTTPBinaryProcess, "dist/face.jpg", "image/jpg", 10)

int main() {

//    WebServer(8080).Run();
    WebServer(8000).Run();
    return 0;
}
