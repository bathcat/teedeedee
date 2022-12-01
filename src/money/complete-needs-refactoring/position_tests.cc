#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "position.h"

using namespace money;

namespace
{

    TEST(PositionTests, AddShouldTotal)
    {
        Position l("EUR", 10);
        Position r("EUR", 25);
        auto total = l.add(r);
        EXPECT_EQ(total.quantity(), 35);
    }

    TEST(PositionTests, AddShouldThrowOnDifferentSymbols)
    {
        Position l("EUR", 10);
        Position r("USD", 25);

        EXPECT_THROW(l.add(r), std::invalid_argument);
    }

}