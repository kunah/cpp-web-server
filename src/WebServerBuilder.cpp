#include "WebServerBuilder.h"

using namespace ws;

WebServerBuilder::WebServerBuilder(uint16_t port) : _port(port) {}

WebServer WebServerBuilder::Build() {

    return {_port};

}