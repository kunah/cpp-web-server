#ifndef CPP_WEB_SERVER_REQUESTHANDLER_H
#define CPP_WEB_SERVER_REQUESTHANDLER_H

#include <mutex>
#include <memory>
#include <string>
#include <utility>
#include <filesystem>
#include <unordered_map>

#include <Logger.h>
#include <URL/URLMapper.h>
#include <URL/PatternURL.h>
#include <HTTPResolver/HTTPMethod.h>
#include <HTTPResolver/ProcessClasses/BaseHTTPProcess.h>

namespace ws {
    namespace internal {

        typedef std::function<std::shared_ptr<http::BaseHTTPProcess>()> functionProcess;

/// Singleton class that stores server mappings for HTTP methods
        class ServerMapping {
        public:
            ServerMapping(ServerMapping &_other) = delete;

            void operator=(ServerMapping &_other) = delete;

            /// Gets instance of the current mappings
            static std::shared_ptr<ServerMapping> Instance();

            /// Register a new uri
            /// \param method HTTP method that will be assigned to this uri
            /// \param uri uri starting from root
            /// \param fnc function that creates object that handles incoming request
            /// \param type type of file to be added to HTTP response Content-Type header section
            static void RegisterURI(http::HTTPMethod method, const std::string &uri, functionProcess fnc);

            /// \return all mapped uris for given method
            const url::URLMapper &GetURIs(http::HTTPMethod method);

            /// \return path of a file for given method and uri mapping
            functionProcess GetProcess(http::HTTPMethod method, url::URL &uri);

        protected:
            /// Protected constructor to preserve singleton architecture
            ServerMapping() = default;

            inline static std::shared_ptr<ServerMapping> instance = nullptr;
            inline static std::mutex instanceMtx = std::mutex();

        private:

            std::mutex methodsMtx;
            std::unordered_map<http::HTTPMethod, url::URLMapper> HTTPMethodsMappings;

        };

    } // namespace internal
} // namespace ws

#endif //CPP_WEB_SERVER_REQUESTHANDLER_H
