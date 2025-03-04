#include "DummyMiddleware.h"
#include "Logger.h"


void ws::DummyMiddleware::Run(ws::http::HTTPContext & httpContext) {
    Logger::info("DummyMiddleware Call", __func__, httpContext.url );
    return;
}
