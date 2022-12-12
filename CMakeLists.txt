cmake_minimum_required(VERSION 3.24)
project(cpp_web_server)

set(CMAKE_CXX_STANDARD 17)

find_package(Threads REQUIRED)

include_directories(include)

add_executable(cpp_web_server main.cpp src/WebServer.cpp src/Logger.cpp src/ThreadPool.cpp)
