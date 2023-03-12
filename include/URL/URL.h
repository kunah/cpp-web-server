#ifndef CPP_WEB_SERVER_URL_H
#define CPP_WEB_SERVER_URL_H

#include <regex>
#include <string>
#include <vector>
#include <unordered_map>

#include <Logger.h>

/// Base class for storing URLs
class URL{
public:
    URL() = default;
    /// Builds a new URL from the URI string
    /// \param _uri the string of the URL
    URL(const std::string & _uri);

    virtual ~URL() = default;

    URL& operator=(std::string & other);
    URL& operator=(const URL & other);

    /// Compares two URL if they are same
    /// \param other other URL to compare with
    /// \return if the URL is mapped on this regex URL
    virtual bool operator==(URL & other);
    /// Compares two URLs if they are the same from the string
    /// \param otherUri the URI to compare with
    /// \return if the URI is mapped on this regex URL
    virtual bool operator==(const std::string &otherUri);
    /// Compares two URLs if they are the same from the string
    /// \param otherUri the URI to compare with
    /// \return if the URI is mapped on this regex URL
    virtual bool operator==(std::string &otherUri);

    /// Outputs on given output stream
    /// \param os std::ostream reference
    /// \param url URL to print
    /// \return std::ostream reference
    friend std::ostream& operator<<(std::ostream & os, URL & url);

    /// \return Whole URL as a string
    std::string GetURL() const;
    /// \return Parts of the URL
    std::vector<std::string> GetParts() const;
    /// \return Mapped values with regex URL
    std::unordered_map<std::string, std::string> GetValues() const;
    /// Sets values for this URL
    void SetValues(std::unordered_map<std::string, std::string>& _values);

protected:

    /// Parse the URI string to separate parts
    void ParseURL();

    std::string uri;

    std::vector<std::string> parts;

    std::unordered_map<std::string, std::string> values;

};

#endif //CPP_WEB_SERVER_URL_H
