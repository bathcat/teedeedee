#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "money.h"

using namespace money;

namespace
{

    TEST(MoneyTests, AddShouldTotal)
    {
        Money l(10);
        Money r(25);
        auto total = l.add(r);
        EXPECT_EQ(total.quantity(), 35);
    }

}