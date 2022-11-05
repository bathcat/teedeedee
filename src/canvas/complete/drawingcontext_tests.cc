#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "drawingcontext.h"
#include "turtle.h"

using ::testing::AtLeast;
using namespace canvas;

class MockTurtle : public Turtle
{
public:
    MOCK_METHOD(void, PenUp, (), (override));
    MOCK_METHOD(void, PenDown, (), (override));
    MOCK_METHOD(void, Forward, (int distance), (override));
    MOCK_METHOD(void, Turn, (int degrees), (override));
    MOCK_METHOD(void, GoTo, (int x, int y), (override));
    MOCK_METHOD(void, PointTo, (int degrees), (override));
    MOCK_METHOD(int, GetX, (), (const, override));
    MOCK_METHOD(int, GetY, (), (const, override));
};

namespace
{

    TEST(CanvasTests, TrueShouldBeTrue)
    {
        MockTurtle turtle;
        EXPECT_CALL(turtle, PenDown())
            .Times(AtLeast(1));

        DrawingContext canvas(turtle);
        canvas.DrawRectangle(0, 0, 0, 0);

        EXPECT_EQ("1", "1");
    }

}