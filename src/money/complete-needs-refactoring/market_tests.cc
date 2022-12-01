#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "market.h"
#include "converter.h"

using namespace money;

namespace
{

    TEST(MarketTests, consolidateShouldUseAppropriateConverter)
    {
        // Arrange
        Market m;
        m.addConverter(Converter("USD", "EUR", 2));
        Position usdPosition("USD", 100);

        // Act
        auto eurPosition = m.consolidate(usdPosition, "EUR");

        // Assert
        EXPECT_EQ(eurPosition.quantity(), 200);
    }

    TEST(MarketTests, consolidateShouldDoNothingWithNoConverter)
    {
        // Arrange
        Market m;
        Position usdPosition("USD", 100);

        // Act
        auto convertedPosition = m.consolidate(usdPosition, "EUR");

        // Assert
        EXPECT_EQ(convertedPosition.quantity(), 100);
        EXPECT_EQ(convertedPosition.symbol(), "USD");
    }

}