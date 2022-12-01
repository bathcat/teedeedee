#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "converter.h"
#include "position.h"

using namespace money;

namespace
{

    TEST(ConverterTests, ConvertShouldTotalCorrectly)
    {
        Converter d2e("USD","FAKE",2);
        auto converted = d2e.convert(50);
        EXPECT_EQ(100,converted.quantity());
    }

    TEST(ConverterTests, ConvertShouldHaveProperSymbol)
    {
        Converter d2e("USD","FAKE",2);
        auto converted = d2e.convert(50);
        EXPECT_EQ("FAKE",converted.symbol());
    }


}