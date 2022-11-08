#include <gtest/gtest.h>
#include "gmock/gmock.h"

#include "fortune.h"

namespace
{

    TEST(GetFortune, TrueShouldBeTrue)
    {
        EXPECT_EQ('1', '1');
    }

}