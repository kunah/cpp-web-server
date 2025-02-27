#include "WebServerBuilder.h"

ws::WebServerBuilder::WebServerBuilder(uint16_t port) : _port(port) {}

ws::WebServer ws::WebServerBuilder::Build() {

    return {_port};

}