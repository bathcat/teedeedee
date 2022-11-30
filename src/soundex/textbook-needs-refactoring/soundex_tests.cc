#include <gtest/gtest.h>
#include "gmock/gmock.h"

#include "soundex.h"

using namespace soundex;

namespace
{

    TEST(SoundexEncoding, ShouldCaptureFirstCharacter)
    {
        const auto result = soundex::encode("Antimony");
        EXPECT_EQ(result[0], 'A');
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