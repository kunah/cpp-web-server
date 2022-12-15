#include "Exceptions/ClientError.h"


HTTPError::ClientError::ClientError(ClientErrorCode _code, bool _webSite, const std::string & _site) : code(_code), webSite(_webSite), site(_site) {}

std::string HTTPError::ClientError::Response() {

    HTTPParser response;



    return response.ToString();
}