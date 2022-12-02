#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "position.h"
#include "portfolio.h"

using namespace money;

namespace
{

    TEST(PortfolioTests, DepositNewShouldStick)
    {
        Portfolio portfolio;
        Position euros("EUR", 22);
        portfolio.deposit(euros);

        EXPECT_EQ(portfolio.positions().at("EUR").quantity(),22);
    }

}