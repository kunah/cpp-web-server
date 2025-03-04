#ifndef CPP_WEB_SERVER_DUMMYMIDDLEWARE_H
#define CPP_WEB_SERVER_DUMMYMIDDLEWARE_H

#include <interface/Middleware.h>

namespace ws {

class DummyMiddleware : public ws::interface::Middleware {
    public:
        DummyMiddleware() = default;

        void Run(ws::http::HTTPContext & httpContext) override;
};

} // namespace ws

#endif //CPP_WEB_SERVER_DUMMYMIDDLEWARE_H
