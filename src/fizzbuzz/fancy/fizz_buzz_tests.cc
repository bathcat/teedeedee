#include <gtest/gtest.h>
#include "fizz_buzz.h"
#include <string>
#include <tuple>

using ::testing::Values;

namespace {

    class GetMessageResultTest :
        public testing::TestWithParam<std::tuple<unsigned short,std::string>> {
    };

    TEST_P(GetMessageResultTest, ShouldMatchExpectation) {
        const auto param = GetParam();
        const auto argument = std::get<0>(param);
        const auto expected = std::get<1>(param);
        
        const auto actual = getMessage(argument);

        EXPECT_EQ(actual,expected);
    }

    std::tuple<unsigned short,std::string> Fizz(unsigned short n){
        return std::make_tuple(n, "Fizz");
    }

    std::tuple<unsigned short,std::string> Buzz(unsigned short n){
        return std::make_tuple(n, "Buzz");
    }

    std::tuple<unsigned short,std::string> FizzBuzz(unsigned short n){
        return std::make_tuple(n, "FizzBuzz");
    }

    INSTANTIATE_TEST_SUITE_P(
        ShouldMatchRules,
        GetMessageResultTest,
        Values(
            Fizz(3), Fizz(6),Fizz(9),
            Buzz(5), Buzz(10),Buzz(20),
            FizzBuzz(15), FizzBuzz(30),FizzBuzz(45)
        )
    );


    TEST(GetMessageTests,  ShouldThrowOn101) {
        EXPECT_THROW(getMessage(101),std::invalid_argument );
    }

}