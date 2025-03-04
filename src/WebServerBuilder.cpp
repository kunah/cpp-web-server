#include "WebServerBuilder.h"

ws::WebServerBuilder::WebServerBuilder(uint16_t port) : _port(port), requestMiddlewares(new std::vector<middlewareInstance>) {}

std::unique_ptr<ws::WebServer> ws::WebServerBuilder::Build() {

    return std::unique_ptr<ws::WebServer>(new ws::WebServer(_port, requestMiddlewares));

}