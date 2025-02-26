#include "Middleware.h"
#include "Logger.h"

using namespace ws;

std::string Middleware::Name() {
    return typeid(this).name();
}

void DummyMiddleware::Run() {
    Logger::info("Call", __func__ );
    return;
}
