#include <iostream>
#include "pi.h"

const std::string usage = R"(
# PI

Command-line application to derive the constant pi.
)";

int main(const int argc, const char **argv)
{
    if (argc > 1)
    {
        std::cout << usage << std::endl;
        return 0;
    }

    std::cout << "Pi is: " << pi::approximatePi() << std::endl;

    return 0;
}
