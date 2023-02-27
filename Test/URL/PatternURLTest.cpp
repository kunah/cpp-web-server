#include <TestMacros.h>
#include <URL/PatternURL.h>

TEST(testPatterURL){
    PatternURL patternUrl("/ahoj/{this}/cau");

    URL first("/ahoj/tohle/cau");
    URL second("/ahoj/nakup/cau");
    URL third("/ahoj/cau");
    URL fourth("/ahoj/tohle/cau/this");
    URL fifth("ahoj/tohle/cau");

    ASSERT_EQ(patternUrl, first)
    ASSERT_EQ(patternUrl, second)

    ASSERT_NOT_EQ(patternUrl, third)
    ASSERT_NOT_EQ(patternUrl, fourth)
    ASSERT_NOT_EQ(patternUrl, fifth)
}
