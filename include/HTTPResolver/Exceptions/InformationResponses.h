#ifndef CPP_WEB_SERVER_INFORMATIONRESPONSES_H
#define CPP_WEB_SERVER_INFORMATIONRESPONSES_H

#include <HTTPResolver/Exceptions/HTTPExceptionBase.h>

namespace HTTPException {
    /// Continue
    /// Error code: 100
    class HTTPContinue : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPContinue(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(
                ErrorCode::Continue,
                "Continue", _webSite,
                _site) {}
    };

    /// Switching Protocols
    /// Error code: 101
    class HTTPSwitchingProtocols : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPSwitchingProtocols(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(
                ErrorCode::SwitchingProtocols,
                "SwitchingProtocols", _webSite,
                _site) {}
    };

    /// Processing
    /// Error code: 102
    class HTTPProcessing : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPProcessing(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(ErrorCode::Processing,
                                                                                                 "Processing", _webSite,
                                                                                                 _site) {}
    };

    /// Early Hints
    /// Error code: 103
    class HTTPEarlyHints : public HTTPExceptionBase {
    public:
        /// \param _webSite if to send a web site back
        /// \param _site path to the site
        HTTPEarlyHints(bool _webSite = false, const std::string &_site = "") : HTTPExceptionBase(
                ErrorCode::EarlyHints,
                "EarlyHints", _webSite,
                _site) {}
    };
}

#endif //CPP_WEB_SERVER_INFORMATIONRESPONSES_H
