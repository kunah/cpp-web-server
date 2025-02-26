#include <TestMacros.h>
#include <URL/PatternURL.h>

using namespace ws::url;

TEST(testPatterURL){
    PatternURL patternUrl("/first/{this}/next");
    PatternURL patternUrlSecond("/first/{this}/next/{that}");

    URL first("/first/that/next");
    URL second("/first/video/next");
    URL third("/first/video/next/this");
    URL fourth("/first/next");
    URL fifth("first/that/next");

    ASSERT_EQ(patternUrl, first)
    ASSERT_EQ(patternUrl, second)
    ASSERT_EQ(patternUrlSecond, third)

    ASSERT_NOT_EQ(patternUrl, fourth)
    ASSERT_NOT_EQ(patternUrl, fifth)
    ASSERT_NOT_EQ(patternUrl, third)
}


TEST(testPatterURLGetValues){
    PatternURL patternUrl("/first/{this}/next");
    PatternURL patternUrlSecond("/first/{this}/next/{that}");

    URL first("/first/that/next");
    URL second("/first/video/next/this");

    ASSERT_EQ(patternUrl, first)
    ASSERT_EQ(patternUrlSecond, second)

    auto val = first.GetValues();
    ASSERT_EQ(val.size(), 1)
    ASSERT_EQ(val["this"], "that")

    val = second.GetValues();
    ASSERT_EQ(val.size(), 2)
    ASSERT_EQ(val["this"], "video")
    ASSERT_EQ(val["that"], "this")
}

TEST(testPatterURLCompareString){
    PatternURL patternUrl("/first/{this}/next");

    ASSERT_EQ(patternUrl, "/first/that/next")
    ASSERT_EQ(patternUrl, "/first/thisIsIt/next")

    ASSERT_NOT_EQ(patternUrl, "/first/that/")
}