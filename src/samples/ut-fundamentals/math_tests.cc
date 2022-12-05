#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "math.h"

using namespace utFundamentals;

namespace
{


    TEST(MathTests, AddShouldSum2Plus2As4)
    {
        EXPECT_EQ(add(2,2), 4);
    }




}