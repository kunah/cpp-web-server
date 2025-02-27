#include <TestMacros.h>
#include <URL/PatternURL.h>

namespace url = ws::url;

TEST(testPatterURL){
    url::PatternURL patternUrl("/first/{this}/next");
    url::PatternURL patternUrlSecond("/first/{this}/next/{that}");

    url::URL first("/first/that/next");
    url::URL second("/first/video/next");
    url::URL third("/first/video/next/this");
    url::URL fourth("/first/next");
    url::URL fifth("first/that/next");

    ASSERT_EQ(patternUrl, first)
    ASSERT_EQ(patternUrl, second)
    ASSERT_EQ(patternUrlSecond, third)

    ASSERT_NOT_EQ(patternUrl, fourth)
    ASSERT_NOT_EQ(patternUrl, fifth)
    ASSERT_NOT_EQ(patternUrl, third)
}


TEST(testPatterURLGetValues){
    url::PatternURL patternUrl("/first/{this}/next");
    url::PatternURL patternUrlSecond("/first/{this}/next/{that}");

    url::URL first("/first/that/next");
    url::URL second("/first/video/next/this");

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
    url::PatternURL patternUrl("/first/{this}/next");

    ASSERT_EQ(patternUrl, "/first/that/next")
    ASSERT_EQ(patternUrl, "/first/thisIsIt/next")

    ASSERT_NOT_EQ(patternUrl, "/first/that/")
}