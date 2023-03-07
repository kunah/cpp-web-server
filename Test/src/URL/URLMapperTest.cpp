#include <TestMacros.h>
#include <URL/URLMapper.h>
#include <ProcessClasses/HTTPTextProcess.h>
#include <memory>

TEST(testUrlMapperEasyRegistreation){

    URLMapper mapper;

    auto testFnc = [](){return std::make_shared<HTTPTextProcess>("dist/Test/testHeader.txt", "text/html");};

    mapper.RegisterURL("/", testFnc);
    mapper.RegisterURL("/test", testFnc);
    mapper.RegisterURL("/ahoj", testFnc);
    mapper.RegisterURL("/ahoj/pokus", testFnc);

    ASSERT_TRUE(mapper.FindURL("/").first)
    ASSERT_TRUE(mapper.FindURL("/test").first)
    ASSERT_TRUE(mapper.FindURL("/ahoj").first)
    ASSERT_TRUE(mapper.FindURL("/ahoj/pokus").first)

    ASSERT_THROW(mapper.FindURL(""), HTTPException::HTTPNotFound)
    ASSERT_THROW(mapper.FindURL("/tady"), HTTPException::HTTPNotFound)
    ASSERT_THROW(mapper.FindURL("/ahoj/pokus/poslendi"), HTTPException::HTTPNotFound)

    ASSERT_THROW(mapper.RegisterURL("/", testFnc), std::runtime_error)
    ASSERT_THROW(mapper.RegisterURL("/ahoj/pokus/", testFnc), std::runtime_error)

}

TEST(testUrlMapperHardRegistreation){

    URLMapper mapper;

    auto testFnc = [](){return std::make_shared<HTTPTextProcess>("dist/Test/testHeader.txt", "text/html");};

    mapper.RegisterURL("/", testFnc);
    mapper.RegisterURL("/{test}", testFnc);
    mapper.RegisterURL("/pokus", testFnc);
    mapper.RegisterURL("/ahoj/{pokus}", testFnc);

    ASSERT_TRUE(mapper.FindURL("/").first)
    ASSERT_TRUE(mapper.FindURL("/test").first)
    ASSERT_TRUE(mapper.FindURL("/pokus").first)
    ASSERT_TRUE(mapper.FindURL("/ahoj/pokus").first)

    ASSERT_THROW(mapper.FindURL(""), HTTPException::HTTPNotFound)
    ASSERT_THROW(mapper.FindURL("/pokus/ahoj"), HTTPException::HTTPNotFound)

    ASSERT_THROW(mapper.RegisterURL("/pokus", testFnc), std::runtime_error)
    ASSERT_THROW(mapper.RegisterURL("/{test2}", testFnc), std::runtime_error)
    ASSERT_THROW(mapper.RegisterURL("/ahoj/{tenhle}", testFnc), std::runtime_error)

    ASSERT_EQ(mapper.FindURL("/ahoj/pokus").second.GetURL(), "/ahoj/[[:alnum:]]+")

}