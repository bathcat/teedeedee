#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "uuid.h"
#include <limits>
#include <bitset>

using namespace uuid;

namespace
{
    TEST(concat, ShouldConcat)
    {
        const std::string lS = "10001";
        std::bitset<5> l(lS);

        const std::string rS = "001110";
        std::bitset<6> r(rS);

        const auto expected = internal::concat(l, r).to_string();
        const auto actual = lS + rS;

        EXPECT_EQ(actual, expected);
    }

    TEST(slice, ShouldGetAppropriateThings)
    {
        const std::bitset<7> original("1100011");
        const auto part = internal::slice<3>(original, 2);

        const auto expected = 0;
        const auto actual = part.to_ulong();

        EXPECT_EQ(actual, expected);
    }

    TEST(toHexDigit, ShouldGetRightChar)
    {
        EXPECT_EQ('a', internal::toHexDigit(std::bitset<4>(10)));
        EXPECT_EQ('0', internal::toHexDigit(std::bitset<4>(0)));
        EXPECT_EQ('c', internal::toHexDigit(std::bitset<4>(12)));
        EXPECT_EQ('3', internal::toHexDigit(std::bitset<4>(3)));
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