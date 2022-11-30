#include <gtest/gtest.h>
#include "gmock/gmock.h"

#include "soundex.h"
#include <range/v3/range/conversion.hpp>
#include <range/v3/view/take.hpp>

using namespace soundex;
using ranges::to;
using ranges::views::take;

namespace
{

    TEST(internalGetPrefix, ShouldTakeFirstThing)
    {
        const auto result = soundex::internal::getPrefix("Antimony") | to<std::string>();
        EXPECT_EQ("A", result);
    }

    TEST(internalGetPadding, ShouldBeZeros)
    {
        const auto result = soundex::internal::getPadding() | take(4) |to<std::string>();
        EXPECT_EQ("0000", result);
    }

    TEST(SoundexEncoding, ShouldPadWithZeros)
    {
        const auto result = soundex::encode("A");
        EXPECT_EQ(result, "A000");
    }

    TEST(SoundexEncoding, ShouldSubstituteNonInitialNumbers)
    {
        EXPECT_EQ("A200", soundex::encode("Ac"));
    }

    TEST(SoundexEncoding, IgnoresVowelLikeLetters)
    {
        EXPECT_EQ("B234",soundex::encode("Baeiouhycdl") );
    }

    TEST(SoundexEncoding, ShouldPreserveDuplicatesWithVowlsBetween)
    {
        EXPECT_EQ("T522", soundex::encode("Tymczak"));
    }

    TEST(SoundexEncoding, ShouldSkipDuplicateFirstLetters)
    {
        EXPECT_EQ("P236", soundex::encode("Pfister"));
    }

    TEST(SoundexEncoding, ShouldCompletelyIgnoreSkippables)
    {
        EXPECT_EQ("H555", soundex::encode("Honeyman"));
    }

}