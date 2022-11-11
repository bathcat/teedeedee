#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "drawing_context.h"
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
    MOCK_METHOD(void, TurnTo, (int degrees), (override));
    MOCK_METHOD(int, GetX, (), (const, override));
    MOCK_METHOD(int, GetY, (), (const, override));
};

namespace
{

    TEST(CanvasTests, PerimeterShouldAddUp)
    {
        MockTurtle turtle;

        const auto w = 10;
        const auto h = 20;

        EXPECT_CALL(turtle, Forward(w))
            .Times(2);

        EXPECT_CALL(turtle, Forward(h))
            .Times(2);

        DrawingContext canvas(turtle);
        canvas.DrawRectangle(0, 0, w, h);
    }

    TEST(CanvasTests, TurnsShouldBe360)
    {
        MockTurtle turtle;

        const auto w = 10;
        const auto h = 20;

        EXPECT_CALL(turtle, Turn(90))
            .Times(4);

        DrawingContext canvas(turtle);
        canvas.DrawRectangle(0, 0, w, h);
    }

}