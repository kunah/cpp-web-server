#ifndef CPP_WEB_SERVER_TESTMACROS_H
#define CPP_WEB_SERVER_TESTMACROS_H

#include <mutex>
#include <vector>
#include <memory>

#include <Logger.h>

class Test{
public:
    Test(std::string _name) : name(_name){}

    inline std::string GetName() const {return name;}

    inline bool Failed() const {return failed;}

    virtual void RunTest() = 0;

protected:
    bool failed = false;
    std::string name;
};

typedef std::shared_ptr<Test> testObj;

/// Singleton class that stores test function
class Tester {
public:
    Tester(Tester & _other) = delete;
    void operator=(Tester & _other) = delete;
    /// Gets instance of the current tester
    static std::shared_ptr<Tester> Instance();
    /// Register a new test
    /// \param test new test
    static void RegisterTest(testObj test);
    /// \return all registered tests
    std::vector<testObj> GetTests();

protected:
    /// Protected constructor to preserve singleton architecture
    Tester() = default;

    inline static std::shared_ptr<Tester> instance = nullptr;
    inline static std::mutex instanceMtx = std::mutex();

private:

    std::mutex testFunctionsMutex;
    std::vector<testObj> testFunctions;

};

/// Base class that registers new test function
class TestFunctionRegistrar{
public:
    TestFunctionRegistrar() = delete;
    /// Register test function
    /// \param test test object
    TestFunctionRegistrar(std::shared_ptr<Test> test);
};

#ifndef CONCAT
    #define CONCAT_(x,y) x##y
    #define CONCAT(x,y) CONCAT_(x,y)
#endif

#define __ASSERT_EQ(first, sec, line) \
if(first != sec) {             \
    failed = true;        \
    std::cerr << "Test: " << __func__ << " failed on line: " << line << std::endl; \
}

#define __ASSERT_NOT_EQ(first, sec, line) \
if(first == sec) {             \
    failed = true;        \
    std::cerr << "Test " << name << " failed in file: " << __FILE__ << " on line: " << line << std::endl; \
}

#define __ASSERT_TRUE(first, line) \
if(!first){                        \
    failed = true;                 \
    std::cerr << "Test: " << __func__ << " failed on line: " << line << std::endl; \
}\

#define __ASSERT_NOT_TRUE(first, line) \
if(first){                        \
    failed = true;                 \
    std::cerr << "Test: " << __func__ << " failed on line: " << line << std::endl; \
}\

#define __ASSERT_THROW(first, exc, line) \
try{                                     \
    first;                               \
    failed = true;                       \
    std::cerr << "Did not throw an exception " << #exc << '\n' << __func__ << " on line: " << line << std::endl;\
}                                        \
catch(exc & e){  \
    Logger::debug(e.what());\
}

#define ASSERT_EQ(first, sec) __ASSERT_EQ(first, sec, __LINE__)

#define ASSERT_NOT_EQ(first, sec) __ASSERT_NOT_EQ(first, sec, __LINE__)

#define ASSERT_TRUE(first) __ASSERT_TRUE(first, __LINE__)

#define ASSERT_NOT_TRUE(first) __ASSERT_NOT_TRUE(first, __LINE__)

#define ASSERT_THROW(first, exc) __ASSERT_THROW(first, exc, __LINE__)

#define TEST(name) \
class name##Test : public Test{ \
public:            \
    name##Test() : Test(#name){}\
    void RunTest() override;\
};       \
static TestFunctionRegistrar CONCAT(testRegister, __COUNTER__)(std::make_shared<name##Test>());\
void name##Test::RunTest()

#define RUN_ALL_TESTS { \
auto tests = Tester::Instance()->GetTests(); \
int i = 0, test = 1;                        \
for(auto t : tests){    \
    Logger::ClearSS();                    \
    std::cout << "Running test " << t->GetName() << " "  << test++ << "/" << tests.size() << std::endl;                    \
    t->RunTest();       \
    if(t->Failed()){    \
        ++i;            \
        std::cout << "Test " << t->GetName() << " failed\nTest output:" << std::endl;                                                                           \
        std::cout << Logger::GetSS();\
    }     \
}\
std::cout << i << " test failed" << std::endl;\
}
#endif //CPP_WEB_SERVER_TESTMACROS_H
