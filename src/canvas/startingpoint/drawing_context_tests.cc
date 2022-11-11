#include <gtest/gtest.h>
#include "gmock/gmock.h"

#include "drawing_context.h"
#include "third_party_library_turtle.h"

namespace
{

    TEST(DrawingContextTests, TrueShouldBeTrue)
    {
        third_party_library::Turtle turtle;
        canvas::DrawingContext context(turtle);
        EXPECT_EQ(true, true);
    }

}