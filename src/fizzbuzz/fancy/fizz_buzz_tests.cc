#include <gtest/gtest.h>
#include "fizz_buzz.h"
#include <string>
#include <tuple>

using ::testing::Values;
using namespace fizzbuzz;

namespace
{

    class GetMessageResultTest : public testing::TestWithParam<std::tuple<unsigned short, std::string>>
    {
    };

    TEST_P(GetMessageResultTest, ShouldMatchExpectation)
    {
        const auto param = GetParam();
        const auto argument = std::get<0>(param);
        const auto expected = std::get<1>(param);

        const auto actual = getMessage(argument);

        EXPECT_EQ(actual, expected);
    }

    auto fizz = [](unsigned short n) {return std::make_tuple(n, "Fizz");};
    auto buzz=[](unsigned short n){return std::make_tuple(n, "Buzz");};
    auto fizzBuzz=[](unsigned short n){return std::make_tuple(n, "FizzBuzz");};

    INSTANTIATE_TEST_SUITE_P(
        ShouldMatchRules,
        GetMessageResultTest,
        Values(
            fizz(3), fizz(6), fizz(9),
            buzz(5), buzz(10), buzz(20),
            fizzBuzz(15), fizzBuzz(30), fizzBuzz(45)));

    TEST(GetMessageTests, ShouldThrowOn101)
    {
        EXPECT_THROW(getMessage(101), std::invalid_argument);
    }

    TEST(GetAllMessagesTests, ShouldHave100Things)
    {
        const auto actual = getAllMessages().size();
        EXPECT_EQ(actual, 100);
    }

}