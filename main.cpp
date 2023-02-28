#include <WebServer.h>
#include <HTTPMappingRegistrar.h>
#include <ProcessClasses/HTTPTextProcess.h>
#include <ProcessClasses/HTTPBinaryProcess.h>


REGISTER_GET_URI("/", HTTPTextProcess, "dist/index.html", "text/html")
REGISTER_GET_URI("/about", HTTPTextProcess, "dist/about.html", "text/html")
REGISTER_GET_URI("/favicon.ico", HTTPBinaryProcess   , "dist/favicon.ico", "image/x-icon", 60)
REGISTER_GET_URI("/face.jpg", HTTPBinaryProcess, "dist/face.jpg", "image/jpg", 10)
REGISTER_GET_URI("/{name}/face.jpg", HTTPBinaryProcess, "dist/face.jpg", "image/jpg", 10)

int main() {

//    WebServer(8080).Run();
    WebServer(8000).Run();
    return 0;
}
