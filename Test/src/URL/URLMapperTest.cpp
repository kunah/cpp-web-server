#include <TestMacros.h>
#include <URL/URLMapper.h>
#include <HTTPResolver/ProcessClasses/HTTPFileProcess.h>
#include <memory>

namespace HTTPException = ws::HTTPException;

TEST(testUrlMapperEasyRegistreation){

    ws::url::URLMapper mapper;

    auto testFnc = [](){return std::make_shared<ws::http::HTTPFileProcess>("dist/Test/testHeader.txt", "text/html");};

    mapper.RegisterURL("/", testFnc);
    mapper.RegisterURL("/test", testFnc);
    mapper.RegisterURL("/first", testFnc);
    mapper.RegisterURL("/first/hello", testFnc);

    ASSERT_TRUE(mapper.FindURL("/").first)
    ASSERT_TRUE(mapper.FindURL("/test").first)
    ASSERT_TRUE(mapper.FindURL("/first").first)
    ASSERT_TRUE(mapper.FindURL("/first/hello").first)

    ASSERT_THROW(mapper.FindURL(""), HTTPException::HTTPNotFound)
    ASSERT_THROW(mapper.FindURL("/tady"), HTTPException::HTTPNotFound)
    ASSERT_THROW(mapper.FindURL("/first/hello/poslendi"), HTTPException::HTTPNotFound)

    ASSERT_THROW(mapper.RegisterURL("/", testFnc), std::runtime_error)
    ASSERT_THROW(mapper.RegisterURL("/first/hello/", testFnc), std::runtime_error)

}

TEST(testUrlMapperHardRegistreation){

    ws::url::URLMapper mapper;

    auto testFnc = [](){return std::make_shared<ws::http::HTTPFileProcess>("dist/Test/testHeader.txt", "text/html");};

    mapper.RegisterURL("/", testFnc);
    mapper.RegisterURL("/{test}", testFnc);
    mapper.RegisterURL("/hello", testFnc);
    mapper.RegisterURL("/first/{hello}", testFnc);
    mapper.RegisterURL("/first/{test}.src", testFnc);

    ASSERT_TRUE(mapper.FindURL("/").first)
    ASSERT_TRUE(mapper.FindURL("/test").first)
    ASSERT_TRUE(mapper.FindURL("/hello").first)
    ASSERT_TRUE(mapper.FindURL("/first/hello").first)
    ASSERT_TRUE(mapper.FindURL("/first/first.src").first)

    ASSERT_THROW(mapper.FindURL(""), HTTPException::HTTPNotFound)
    ASSERT_THROW(mapper.FindURL("/hello/first"), HTTPException::HTTPNotFound)
    ASSERT_THROW(mapper.FindURL("/hello/second.srr"), HTTPException::HTTPNotFound)

    ASSERT_THROW(mapper.RegisterURL("/hello", testFnc), std::runtime_error)
    ASSERT_THROW(mapper.RegisterURL("/{test2}", testFnc), std::runtime_error)
    ASSERT_THROW(mapper.RegisterURL("/first/{this}", testFnc), std::runtime_error)

    ASSERT_EQ(mapper.FindURL("/first/hello").second.GetURL(), "/first/[[:alnum:]]+")
    ASSERT_EQ(mapper.FindURL("/first/third.src").second.GetURL(), "/first/[[:alnum:]]+.src")

}