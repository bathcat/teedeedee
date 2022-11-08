#include <gtest/gtest.h>
#include "fizz_buzz.h"

namespace {

    TEST(GetMessageTests,  ShouldhandleTheDefaultCase) {
        const auto actual = getMessage(1);
        EXPECT_EQ(actual,"1");
    }

    TEST(GetMessageTests,  ShouldBeFizzFor3) {
        const auto actual = getMessage(3);
        EXPECT_EQ(actual,"Fizz");
    }

    TEST(GetMessageTests,  ShouldBeBuzzFor5) {
        const auto actual = getMessage(5);
        EXPECT_EQ(actual,"Buzz");
    }

    TEST(GetMessageTests,  ShouldBeFizzBuzzFor15) {
        const auto actual = getMessage(15);
        EXPECT_EQ(actual,"FizzBuzz");
    }

    TEST(GetMessageTests,  ShouldThrowOn101) {
        EXPECT_THROW(getMessage(101),std::invalid_argument );
    }

}