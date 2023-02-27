#include <TestMacros.h>

std::shared_ptr<Tester> Tester::Instance() {
    std::unique_lock<std::mutex> lk(instanceMtx);
    if(!instance)
        instance = std::shared_ptr<Tester>(new Tester);
    return  instance;
}


void Tester::RegisterTest(testObj testFunction) {
    Tester::Instance(); // make sure to init Tester
    std::unique_lock<std::mutex> lkM(instance->testFunctionsMutex);
    instance->testFunctions.emplace_back(testFunction);
}

std::vector<testObj> Tester::GetTests() {
    std::unique_lock<std::mutex> lk(testFunctionsMutex);
    return testFunctions;
}

TestFunctionRegistrar::TestFunctionRegistrar(std::shared_ptr<Test> test) {
    Logger::debug("Registering new test:", test->GetName());
    Tester::Instance()->RegisterTest(test);
}