#include <iostream>
#include "drawing_context.h"
#include "third_party_library_turtle.h"

const std::string usage = R"(
# Canvas

This is a concept-based solution. Key points:
  - The interface is represented as a concept, canvas::Turtle
  - The consumer canvas::DrawingContext is templatized, requiring the concept
  - No need for an adapter class (not yet), since the third-party library matches the concept

Pros:
  - No runtime overhead
  - No boilerplate
  - Abstractions are captured
  - Nice error messages

Cons:
  - Needs > C++20

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
