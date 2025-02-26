#ifndef CPP_WEB_SERVER_WEBSERVERBUILDER_H
#define CPP_WEB_SERVER_WEBSERVERBUILDER_H

#include <list>
#include <memory>

#include "WebServer.h"
#include "Middleware.h"

template<class Base, class Derived>
struct is_strict_base_of
        : std::bool_constant<std::is_base_of<Base, Derived>::value && !std::is_same<Base, Derived>::value> {};

namespace ws {

    typedef std::shared_ptr<Middleware> middlewareInstance;

    class WebServerBuilder {

    public:
        explicit WebServerBuilder(uint16_t port);

        WebServer Build();

        template<typename TMiddleware,
                typename std::enable_if<is_strict_base_of<Middleware, TMiddleware>::value, bool>::type = true>
        WebServerBuilder &AddMiddleware() {

            middlewareInstance middleware = std::make_shared<TMiddleware>();

            auto res = std::find_if(requestMiddlewares.begin(), requestMiddlewares.end(),
                                    [&middleware](auto i) { return middleware->Name() == i->Name(); });

            if (res != requestMiddlewares.end())
                throw std::runtime_error(std::format("Middleware {} is already registered!", middleware->Name()));

            Logger::debug("Adding", middleware->Name());

            requestMiddlewares.push_back(middleware);

            return *this;
        }

//    WebServerBuilder & AddEndpoint();
//
//    WebServerBuilder & AddEndpoints();

    private:

        uint16_t _port;

        std::list<middlewareInstance> requestMiddlewares;

    };

}



#endif //CPP_WEB_SERVER_WEBSERVERBUILDER_H
