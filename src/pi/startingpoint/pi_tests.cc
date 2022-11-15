#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "pi.h"

namespace
{
    TEST(approximatePi, ShouldBeOver3o14)
    {
        EXPECT_TRUE(pi::approximatePi() > 3.14);
    } 
    
    TEST(approximatePi, ShouldBeUnder3o15)
    {
        EXPECT_TRUE(pi::approximatePi() < 3.15);
    }

}