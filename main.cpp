#include <WebServer.h>
#include <HTTPResolver/HTTPMappingRegistrar.h>
#include <HTTPResolver/ProcessClasses/HTTPTextProcess.h>
#include <HTTPResolver/ProcessClasses/HTTPBinaryProcess.h>
#include "WebServerBuilder.h"
#include "DummyMiddleware.h"

REGISTER_GET_URI("/", ws::http::HTTPTextProcess, "dist/index.html", "text/html")
REGISTER_GET_URI("/about", ws::http::HTTPTextProcess, "dist/about.html", "text/html")
REGISTER_GET_URI("/favicon.ico", ws::http::HTTPBinaryProcess   , "dist/favicon.ico", "image/x-icon", 60)
REGISTER_GET_URI("/face.jpg", ws::http::HTTPBinaryProcess, "dist/cpp-icon.png", "image/png", 10)
REGISTER_GET_URI("/photo/{name}/face.jpg", ws::http::HTTPBinaryProcess, "dist/cpp-icon.png", "image/png", 10)
REGISTER_GET_URI("/photo/{name}.jpg", ws::http::HTTPBinaryProcess, "dist/cpp-icon.png", "image/png", 10)

int main() {

    auto builder = ws::WebServerBuilder(8080);
    builder.AddMiddleware<ws::DummyMiddleware>();

    builder.Build()->Run();

    return 0;
}
