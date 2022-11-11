#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "drawingcontext.h"

using ::testing::AtLeast;
using namespace canvas;

class MockTurtle
{
public:
    MOCK_METHOD(void, PenUp, (), ());
    MOCK_METHOD(void, PenDown, (), ());
    MOCK_METHOD(void, Forward, (int distance), ());
    MOCK_METHOD(void, Turn, (int degrees), ());
    MOCK_METHOD(void, GoTo, (int x, int y), ());
    MOCK_METHOD(void, TurnTo, (int degrees), ());
    MOCK_METHOD(int, GetX, (), ());
    MOCK_METHOD(int, GetY, (), ());
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

        DrawingContext<MockTurtle> canvas(turtle);
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