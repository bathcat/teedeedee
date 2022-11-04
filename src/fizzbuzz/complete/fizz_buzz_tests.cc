#include <gtest/gtest.h>
#include "fizz_buzz.h"


TEST(get_message_tests,  should_handle_the_default_case) {
    const auto actual = get_message(1);
    EXPECT_EQ(actual,"1");
}

TEST(get_message_tests,  should_be_Fizz_for_3) {
    const auto actual = get_message(3);
    EXPECT_EQ(actual,"Fizz");
}

TEST(get_message_tests,  should_be_Buzz_for_5) {
    const auto actual = get_message(5);
    EXPECT_EQ(actual,"Buzz");
}

TEST(get_message_tests,  should_be_FizzBuzz_for_15) {
    const auto actual = get_message(15);
    EXPECT_EQ(actual,"FizzBuzz");
}

TEST(get_message_tests,  should_throw_on_101) {
    EXPECT_THROW(get_message(101),std::invalid_argument );
}