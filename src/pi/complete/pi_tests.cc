#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include <functional>
#include "pi.h"

namespace
{
    TEST(approximatePi, TotalAreaShouldBe4)
    {
        std::function<float()> next = [](){return 0.5;};
        const auto actual = pi::approximatePi(next);
        EXPECT_EQ(actual,4.0);
    }

    TEST(approximatePi, InfintesimalCircleShouldBe0)
    {
        std::function<float()> next = [](){return 0.999;};
        const auto actual = pi::approximatePi(next);
        EXPECT_EQ(actual,0.0);
    }

}