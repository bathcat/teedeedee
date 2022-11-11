#include <iostream>
#include "drawing_context.h"
#include "third_party_library_turtle.h"

const std::string usage = R"(
# Canvas

Command-line application that draws some things using a third-party Turtle library.

Pros:
  - Seems to work

Cons:
  - No way to test
  - Our component canvas::DrawingContext is tightly coupled to a third-party library
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
    canvas::DrawingContext context(turtle);
    context.DrawRectangle(10, 10, 5, 5);

    return 0;
}
