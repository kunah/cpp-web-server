#ifndef CPP_WEB_SERVER_REQUESTHANDLER_H
#define CPP_WEB_SERVER_REQUESTHANDLER_H

#include <unordered_map>
#include <memory>
#include <string>
#include <filesystem>
#include <mutex>

#include <Logger.h>

class ServerMapping {
public:
    ServerMapping(ServerMapping & _other) = delete;
    void operator=(ServerMapping & _other) = delete;

    static std::shared_ptr<ServerMapping> Instance();

    void Add(const std::string & uri, const std::string & path);

    std::filesystem::path GetMapping(std::string & uri);

protected:
    ServerMapping() = default;

    inline static std::shared_ptr<ServerMapping> handler = nullptr;
    inline static std::mutex singletonMtx = std::mutex();

private:

    std::mutex mappingMtx;
    std::unordered_map<std::string, std::filesystem::path> mappings;

};


#endif //CPP_WEB_SERVER_REQUESTHANDLER_H
