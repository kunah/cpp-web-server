cmake_minimum_required(VERSION 3.24)
project(cpp_web_server)

set(CMAKE_CXX_STANDARD 17)

find_package(Threads REQUIRED)

include_directories(include)

add_executable(cpp_web_server
        main.cpp
        src/WebServer.cpp
        src/Logger.cpp
        src/ThreadPool.cpp
        src/ClientRequest.cpp
        src/HTTPParser.cpp
        src/ServerMapping.cpp
        src/States/HTTPState.cpp
        src/Exceptions/ClientError.cpp
        src/Exceptions/HTTPExceptionBase.cpp
        src/HTTPMappingRegistrar.cpp)

set(CMAKE_CXX_FLAGS -pthread)

file(REMOVE "${CMAKE_CURRENT_BINARY_DIR}/dist")

file(GLOB files "dist/*")
foreach(file ${files})
    message(STATUS ${file})
    file(COPY ${file} DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/dist")
endforeach()
