#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "uuid.h"
#include <limits>

using namespace uuid;

namespace
{
    TEST(toBits, ShouldConvertAllTrues)
    {
        const char argument = 0b11111111;
        const auto actual = uuid::internal::to_bits(argument);
        EXPECT_TRUE(actual[0]);
        EXPECT_TRUE(actual[1]);
        EXPECT_TRUE(actual[2]);
        EXPECT_TRUE(actual[3]);
        EXPECT_TRUE(actual[4]);
        EXPECT_TRUE(actual[5]);
        EXPECT_TRUE(actual[6]);
        EXPECT_TRUE(actual[7]);
    }


    // TEST(getLowBits, ShouldPreserveLowBits)
    // {
    //     const unsigned long expected = 5;
    //     const auto actual = uuid::internal::getLowBits(expected);
    //     EXPECT_EQ(expected, actual);
    // }

    // TEST(getLowBits, ShouldThrowAwayHighBits)
    // {
    //     const auto expected = 5;
    //     const auto actual = uuid::internal::getLowBits(expected | 0xFF00000000000000);
    //     EXPECT_EQ(expected, actual);
    // }

    // TEST(getMiddleBits, ShouldKeepCenterBits)
    // {
    //     const unsigned short expected = 5;
    //     const auto actual = uuid::internal::getMiddleBits(expected << 24);
    //     EXPECT_EQ(expected, actual);
    // }

    // TEST(getMiddleBits, ShouldThrowOutWingBits)
    // {
    //     const unsigned short expected = 5;
    //     const auto actual = uuid::internal::getMiddleBits((expected << 24)| 0xFFFFFF0000FFFFFF);
    //     EXPECT_EQ(expected, actual);
    // }

}