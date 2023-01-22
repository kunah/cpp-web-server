#ifndef CPP_WEB_SERVER_BASEHTTPCONTENTPROCESS_H
#define CPP_WEB_SERVER_BASEHTTPCONTENTPROCESS_H

#include <string>
#include <utility>
#include <fstream>

#include <Logger.h>
#include <ProcessClasses/BaseHTTPProcess.h>

/// Base API class for handling content sending request (images, text files, etc.)
class BaseHTTPContentProcess : public BaseHTTPProcess{
public:
    /// \param _filePath path to the file to be send
    /// \param _contentType content of that file
    BaseHTTPContentProcess(std::string  _filePath, std::string  _contentType);
    virtual ~BaseHTTPContentProcess() = default;

    /// Default method that sends the file as raw bytes without any modifications
    /// \param request Request to handle
    /// \return Answer for the server to send
    HTTPParser Process(HTTPParser & request) override;

protected:

    std::string filePath;
    std::string contentType;

private:

};

#endif //CPP_WEB_SERVER_BASEHTTPCONTENTPROCESS_H
