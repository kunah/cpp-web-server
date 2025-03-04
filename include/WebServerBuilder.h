#ifndef CPP_WEB_SERVER_WEBSERVERBUILDER_H
#define CPP_WEB_SERVER_WEBSERVERBUILDER_H

#include <vector>
#include <memory>

#include "WebServer.h"
#include "interface/Middleware.h"

/// Type comparer
/// \tparam Base
/// \tparam Derived
template<class Base, class Derived>
struct is_strict_base_of
        : std::bool_constant<std::is_base_of<Base, Derived>::value && !std::is_same<Base, Derived>::value> {};

namespace ws {

    typedef std::shared_ptr<ws::interface::Middleware> middlewareInstance;

    class WebServerBuilder{

    public:

        explicit WebServerBuilder(uint16_t port);

        /// Creates the web server
        /// \return
        virtual std::unique_ptr<ws::WebServer> Build();

        /// Ads middleware to the middleware pipeline of the web server
        /// \warning First added middleware will be the first middleware in the request processing pipeline
        /// \warning Only one instance of the Middleware type is allowed
        /// \tparam TMiddleware subtype of Middleware
        /// \return reference to this builder
        template<typename TMiddleware,
                typename std::enable_if<is_strict_base_of<ws::interface::Middleware, TMiddleware>::value, bool>::type = true>
        WebServerBuilder &AddMiddleware() {

            middlewareInstance middleware = std::make_shared<TMiddleware>();

            auto res = std::find_if(requestMiddlewares->begin(), requestMiddlewares->end(),
                                    [&middleware](auto i) { return middleware->Name() == i->Name(); });

            if (res != requestMiddlewares->end())
                throw std::runtime_error(std::format("Middleware {} is already registered!", middleware->Name()));

            Logger::debug("Adding", middleware->Name());

            requestMiddlewares->push_back(middleware);

            return *this;
        }

//    WebServerBuilder & AddEndpoint();
//
//    WebServerBuilder & AddEndpoints();

    private:

        uint16_t _port;

        std::shared_ptr<std::vector<middlewareInstance>> requestMiddlewares;

    };

} // namespace ws



#endif //CPP_WEB_SERVER_WEBSERVERBUILDER_H
