#include <WebServer.h>
#include <HTTPResolver/HTTPMappingRegistrar.h>
#include <HTTPResolver/ProcessClasses/HTTPFileProcess.h>
#include "WebServerBuilder.h"
#include "DummyMiddleware.h"

REGISTER_GET_URI("/", ws::http::HTTPFileProcess, "dist/index.html", "text/html")
REGISTER_GET_URI("/about", ws::http::HTTPFileProcess, "dist/about.html", "text/html")
REGISTER_GET_URI("/favicon.ico", ws::http::HTTPFileProcess   , "dist/favicon.ico", "image/x-icon", 60)
REGISTER_GET_URI("/face.jpg", ws::http::HTTPFileProcess, "dist/cpp-icon.png", "image/png", 10)
REGISTER_GET_URI("/photo/{name}/face.jpg", ws::http::HTTPFileProcess, "dist/cpp-icon.png", "image/png", 10)
REGISTER_GET_URI("/photo/{name}.jpg", ws::http::HTTPFileProcess, "dist/cpp-icon.png", "image/png", 10)

int main() {

    auto builder = ws::WebServerBuilder(8080);
    builder.AddMiddleware<ws::DummyMiddleware>();

    builder.Build()->Run();

    return 0;
}
