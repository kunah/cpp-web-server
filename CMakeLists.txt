cmake_minimum_required(VERSION 3.22)
project(cpp_web_server)

set(CMAKE_CXX_STANDARD 20)

find_package(Threads REQUIRED)

include_directories(include Test/include)

set(SRC_FILES src/WebServer.cpp
        src/Logger.cpp
        src/ThreadPool.cpp
        src/ClientRequest.cpp
        src/HTTPResolver/HTTPParser.cpp
        src/ServerMapping.cpp
        src/HTTPResolver/States/HTTPState.cpp
        src/HTTPResolver/Exceptions/ClientError.cpp
        src/HTTPResolver/Exceptions/HTTPExceptionBase.cpp
        src/HTTPResolver/Exceptions/ServerError.cpp
        src/HTTPResolver/Exceptions/RedirectionMessages.cpp
        src/HTTPResolver/Exceptions/SuccessfulResponses.cpp
        src/HTTPResolver/Exceptions/InformationResponses.cpp
        src/HTTPResolver/HTTPMappingRegistrar.cpp
        src/HTTPResolver/ProcessClasses/BaseHTTPProcess.cpp
        src/HTTPResolver/ProcessClasses/HTTPTextProcess.cpp
        src/HTTPResolver/ProcessClasses/BaseHTTPContentProcess.cpp
        src/HTTPResolver/ProcessClasses/HTTPBinaryProcess.cpp
        src/URL/URL.cpp
        src/URL/PatternURL.cpp
        src/URL/URLMapper.cpp)

MESSAGE(STATUS ${SRC_FILES})

add_executable(cpp_web_server
        main.cpp

        ${SRC_FILES})

add_executable(Test_cpp_web_server
        ${SRC_FILES}

        Test/main.cpp
        Test/src/URL/PatternURLTest.cpp
        Test/src/TestMacros.cpp
        Test/src/HTTPParserTest.cpp
        Test/src/URL/URLTest.cpp
        Test/src/URL/URLMapperTest.cpp)

target_compile_definitions(cpp_web_server PRIVATE LOG_LEVEL=Logger::Level::INFO)

target_compile_definitions(Test_cpp_web_server PRIVATE LOG_LEVEL=Logger::Level::TEST)


set(CMAKE_CXX_FLAGS -pthread)

file(REMOVE "${CMAKE_CURRENT_BINARY_DIR}/dist")

file(GLOB files "dist/*")
foreach(file ${files})
    message(STATUS ${file})
    file(COPY ${file} DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/dist")
endforeach()
