cmake_minimum_required(VERSION 3.24)
project(cpp_web_server)

set(CMAKE_CXX_STANDARD 20)

find_package(Threads REQUIRED)

include_directories(include Test/include)

set(SRC_FILES src/WebServer.cpp
        src/Logger.cpp
        src/ThreadPool.cpp
        src/ClientRequest.cpp
        src/HTTPParser.cpp
        src/ServerMapping.cpp
        src/States/HTTPState.cpp
        src/Exceptions/ClientError.cpp
        src/Exceptions/HTTPExceptionBase.cpp
        src/Exceptions/ServerError.cpp
        src/Exceptions/RedirectionMessages.cpp
        src/Exceptions/SuccessfulResponses.cpp
        src/Exceptions/InformationResponses.cpp
        src/HTTPMappingRegistrar.cpp
        src/ProcessClasses/BaseHTTPProcess.cpp
        src/ProcessClasses/HTTPTextProcess.cpp
        src/ProcessClasses/BaseHTTPContentProcess.cpp
        src/ProcessClasses/HTTPBinaryProcess.cpp
        src/URL/URL.cpp
        src/URL/PatternURL.cpp)

MESSAGE(STATUS ${SRC_FILES})

add_executable(cpp_web_server
        main.cpp

        ${SRC_FILES})

add_executable(Test_cpp_web_server
        Test/main.cpp
        Test/src/URL/PatternURLTest.cpp
        Test/src/TestMacros.cpp

        ${SRC_FILES} Test/src/HTTPParserTest.cpp)

target_compile_definitions(cpp_web_server PRIVATE LOG_LEVEL=Logger::Level::DEBUG)

target_compile_definitions(Test_cpp_web_server PRIVATE LOG_LEVEL=Logger::Level::WARN)


set(CMAKE_CXX_FLAGS -pthread)

file(REMOVE "${CMAKE_CURRENT_BINARY_DIR}/dist")

file(GLOB files "dist/*")
foreach(file ${files})
    message(STATUS ${file})
    file(COPY ${file} DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/dist")
endforeach()
