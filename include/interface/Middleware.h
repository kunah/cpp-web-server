#ifndef CPP_WEB_SERVER_MIDDLEWARE_H
#define CPP_WEB_SERVER_MIDDLEWARE_H

#include <string>

#include "HTTPResolver/HTTPContext.h"

namespace ws::interface {

    class Middleware {
    public:

        virtual ~Middleware() = default;

        virtual void Run(ws::http::HTTPContext & httpContext) = 0;

        /// Get the middleware type name
        /// \return the typeid(Middleware).name()
        inline std::string Name() const {
            return typeid(this).name();
        };

    };

} //namespace ws::interface


#endif //CPP_WEB_SERVER_MIDDLEWARE_H
