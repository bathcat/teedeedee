#include <iostream>
#include "market.h"
#include "portfolio.h"
#include "converter.h"
#include "position.h"

const std::string usage = R"(
# Money

Command-line application to convert money.
)";

using namespace money;

int main(const int argc, const char **argv)
{
    if (argc > 1)
    {
        std::cout << usage << std::endl;
        return 0;
    }

    Portfolio original;
    original.deposit(Position("MSFT",1000));
    original.deposit(Position("ABC",200));

    original.report(std::cout);

    return 0;
}
