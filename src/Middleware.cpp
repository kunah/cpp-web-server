#include "Middleware.h"
#include "Logger.h"

std::string ws::Middleware::Name() {
    return typeid(this).name();
}

void ws::DummyMiddleware::Run() {
    Logger::info("Call", __func__ );
    return;
}
