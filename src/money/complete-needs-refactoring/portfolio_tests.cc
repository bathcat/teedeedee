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
        portfolio.deposit(Position("EUR", 22));

        EXPECT_EQ(portfolio.positions().at("EUR").quantity(),22);
    }

    TEST(PortfolioTests, DuplicateDepositsShouldAdd)
    {
        Portfolio portfolio;
    
        portfolio.deposit(Position("EUR", 22));
        portfolio.deposit(Position("USD", 900));
        portfolio.deposit(Position("EUR", 22));

        EXPECT_EQ(portfolio.positions().at("EUR").quantity(),44);
    }

}