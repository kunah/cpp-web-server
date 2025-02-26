#ifndef CPP_WEB_SERVER_MIDDLEWARE_H
#define CPP_WEB_SERVER_MIDDLEWARE_H

#include <functional>

namespace ws {

    class Middleware {
    public:

        virtual ~Middleware() = default;

        virtual void Run() = 0;

        virtual std::string Name() final;
    };

    class DummyMiddleware : public Middleware {
    public:
        DummyMiddleware() = default;

        void Run() override;
    };

}


#endif //CPP_WEB_SERVER_MIDDLEWARE_H
