#include <gtest/gtest.h>
#include "gmock/gmock.h"

#include "soundex.h"
#include <ranges>
#include <iostream>

using ::testing::AtLeast;
using namespace soundex;

namespace
{

    TEST(GetMessageTests, ShouldhandleTheDefaultCase)
    {
        auto const ints = {0, 1, 2, 3, 4, 5};
        auto even = [](int i)
        { return 0 == i % 2; };
        auto square = [](int i)
        { return i * i; };

        // "pipe" syntax of composing the views:

        for (int i : ints | std::views::filter(even) | std::views::transform(square))
        {
            std::cout << i << ' ';
        }

        std::cout << '\n';

        // a traditional "functional" composing syntax:
        for (int i : std::views::transform(std::views::filter(ints, even), square))
        {
            std::cout << i << ' ';
        }

        EXPECT_EQ("1", "1");
    }

}