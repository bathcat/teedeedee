#include <gtest/gtest.h>
#include "gmock/gmock.h"

#include <vector>
#include "math.h"

using namespace dependencies;

namespace
{


    TEST(MathTests, AddShouldSum2Plus2As4)
    {
        EXPECT_EQ(add(2,2), 4);
    }

    TEST(MathTests, GetAverageShouldHandleTrivialCase)
    {
        std::vector<int> ns = {4,4,4,4};
        auto actual = getAverage(ns);
        EXPECT_EQ(actual, 4);
    }


}