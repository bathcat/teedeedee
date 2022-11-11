#include <iostream>
#include "drawing_context.h"
#include "third_party_library_turtle.h"
#include "turtle_adapter.h"

const std::string usage = R"(
# Canvas

This is the classic dependency injection described here: 
  https://google.github.io/googletest/gmock_for_dummies.html#a-case-for-mock-turtles

Key points:
  - The interface canvas::Turtle represents an injectable dependency
  - The consumer canvas::DrawingContext takes a reference to the interface in its constructor
  - The wrapper class canvas::TurtleAdapter conforms the implementation (third_party_library::Turtle) to the interface

Pros:
  - Dependencies are explicit
  - Interfaces are easy to mock
  - The third party library is only use directly in one place, making it easy to swap out later.

Cons:
  - Boilerplate code
  - Virtual methods add runtime overhead 

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
    canvas::TurtleAdapter turtleAdapter(turtle);
    canvas::DrawingContext context(turtleAdapter);
    context.DrawRectangle(10, 10, 5, 5);

    return 0;
}
