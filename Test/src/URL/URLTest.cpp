#include <TestMacros.h>
#include <URL/URL.h>

#include <algorithm>

using namespace ws::url;

TEST(testURL){

    URL main("/");
    URL about("/about");
    URL test("/test/");

    std::ostringstream oss;
    std::ostringstream res;
    oss.str("");
    res.str("");

    res << '/' << std::endl;
    res << "Uri parts" << std::endl;


    oss << main;
    std::string first = oss.str();
    std::string second = res.str();
    ASSERT_EQ(oss.str(), res.str())
    oss.str("");
    res.str("");

    res << "/about" << std::endl;
    res << "Uri parts" << std::endl;
    res << "\t0 about" << std::endl;

    oss << about;
    ASSERT_EQ(oss.str(), res.str())
    oss.str("");
    res.str("");

    res << "/test/" << std::endl;
    res << "Uri parts" << std::endl;
    res << "\t0 test" << std::endl;

    oss << test;
    ASSERT_EQ(oss.str(), res.str())

}