#include <gtest/gtest.h>
#include "gmock/gmock.h"

#include "soundex.h"
#include <ranges>
#include <iostream>

using ::testing::AtLeast;
using namespace soundex;

namespace
{

    TEST(GetMessageTests, ShouldhandleTheDefaultCase)
    {
        EXPECT_EQ("A000", soundex::encode("A"));
        EXPECT_EQ("T522", soundex::encode("Tymczak"));
        EXPECT_EQ("H555", soundex::encode("Honeyman"));
        EXPECT_EQ("P236", soundex::encode("Pfister"));
    }

}