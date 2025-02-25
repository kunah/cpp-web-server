#include "WebServerBuilder.h"


WebServerBuilder::WebServerBuilder(uint16_t port) : _port(port) {}

WebServer WebServerBuilder::Build() {

    return WebServer(_port);

}