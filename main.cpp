#include <WebServer.h>
#include <HTTPResolver/HTTPMappingRegistrar.h>
#include <HTTPResolver/ProcessClasses/HTTPTextProcess.h>
#include <HTTPResolver/ProcessClasses/HTTPBinaryProcess.h>
#include "WebServerBuilder.h"

using namespace ws;

REGISTER_GET_URI("/", http::HTTPTextProcess, "dist/index.html", "text/html")
REGISTER_GET_URI("/about", http::HTTPTextProcess, "dist/about.html", "text/html")
REGISTER_GET_URI("/favicon.ico", http::HTTPBinaryProcess   , "dist/favicon.ico", "image/x-icon", 60)
REGISTER_GET_URI("/face.jpg", http::HTTPBinaryProcess, "dist/face.jpg", "image/jpg", 10)
REGISTER_GET_URI("/photo/{name}/face.jpg", http::HTTPBinaryProcess, "dist/face.jpg", "image/jpg", 10)
REGISTER_GET_URI("/photo/{name}.jpg", http::HTTPBinaryProcess, "dist/face.jpg", "image/jpg", 10)

int main() {

    auto builder = WebServerBuilder(8080);
    builder.AddMiddleware<DummyMiddleware>();

//    WebServer(8080).Run();
//    WebServer(8000).Run();
    return 0;
}
