#include <iostream>
#include "money.h"

const std::string usage = R"(
# Money

Command-line application to convert money.
)";

int main(const int argc, const char **argv)
{
    if (argc > 1)
    {
        std::cout << usage << std::endl;
        return 0;
    }

    std::cout << "TODO: Do money stuff" << std::endl;

    return 0;
}
