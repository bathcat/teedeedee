#include <iostream>
#include "drawing_context.h"
#include "third_party_library_turtle.h"

const std::string usage = R"(
# Canvas

This is a template based solution as desribed by goggle test here: 
  https://google.github.io/googletest/gmock_cook_book.html#MockingNonVirtualMethods

Rather than taking an abstract base class, DrawingContext (the consuming code) is templatized.

Pros:
  - No overhead from virtual functions
  - No boilerplate adapter class

Cons:
  - Confusing error messages
  - Turtle interface is an uncaptured abstraction.

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
