cmake_minimum_required(VERSION 3.24)
project(cpp_web_server)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(cpp_web_server main.cpp src/HTTPParser.cpp src/WebServer.cpp)
