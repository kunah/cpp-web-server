#include <TestMacros.h>
#include <URL/PatternURL.h>

TEST(testPatterURL){
    PatternURL patternUrl("/ahoj/{this}/cau");
    PatternURL patternUrlSecond("/ahoj/{this}/cau/{that}");

    URL first("/ahoj/tohle/cau");
    URL second("/ahoj/nakup/cau");
    URL third("/ahoj/nakup/cau/this");
    URL fourth("/ahoj/cau");
    URL fifth("ahoj/tohle/cau");

    ASSERT_EQ(patternUrl, first)
    ASSERT_EQ(patternUrl, second)
    ASSERT_EQ(patternUrlSecond, third)

    ASSERT_NOT_EQ(patternUrl, fourth)
    ASSERT_NOT_EQ(patternUrl, fifth)
    ASSERT_NOT_EQ(patternUrl, third)
}


TEST(testPatterURLGetValues){
    PatternURL patternUrl("/ahoj/{this}/cau");
    PatternURL patternUrlSecond("/ahoj/{this}/cau/{that}");

    URL first("/ahoj/tohle/cau");
    URL second("/ahoj/nakup/cau/this");

    ASSERT_EQ(patternUrl, first)
    ASSERT_EQ(patternUrlSecond, second)

    auto val = first.GetValues();
    ASSERT_EQ(val.size(), 1)
    ASSERT_EQ(val["this"], "tohle")

    val = second.GetValues();
    ASSERT_EQ(val.size(), 2)
    ASSERT_EQ(val["this"], "nakup")
    ASSERT_EQ(val["that"], "this")
}

TEST(testPatterURLCompareString){
    PatternURL patternUrl("/ahoj/{this}/cau");

    ASSERT_EQ(patternUrl, "/ahoj/tohle/cau")
    ASSERT_EQ(patternUrl, "/ahoj/thisIsIt/cau")

    ASSERT_NOT_EQ(patternUrl, "/ahoj/tohle/")
}