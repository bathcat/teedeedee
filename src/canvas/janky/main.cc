#include <iostream>
#include "drawing_context.h"
#include "third_party_library_turtle.h"

const std::string usage = R"(
Canvas
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nam sed justo a nulla luctus bibendum. Sed 
at augue pretium, molestie lorem non, suscipit lectus. Curabitur sed odio eget turpis facilisis 
ultrices sed eget turpis. Vivamus et lorem arcu. Suspendisse ultrices libero non purus dictum aliquam.
)";

int main(const int argc, const char **argv)
{
    if (argc > 1)
    {
        std::cout << usage << std::endl;
        return 0;
    }

    std::cout << "Drawing stuff!" << std::endl;
    third_party_library::Turtle turtle;
    canvas::DrawingContext<third_party_library::Turtle> context(turtle);
    context.DrawRectangle(10, 10, 5, 5);

    return 0;
}
