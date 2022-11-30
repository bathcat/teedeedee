#include <gtest/gtest.h>
#include "gmock/gmock.h"

#include "soundex.h"
#include <ranges>
#include <iostream>

using ::testing::AtLeast;
using namespace soundex;

namespace
{

    TEST(GetMessageTests, TrueShouldBeTrue)
    {
        EXPECT_TRUE(true);
    }

}