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
    std::cout << "====================" << std::endl;
    original.report(std::cout);

    Market m;
    m.addConverter(Converter("MSFT","USD",95.));
    m.addConverter(Converter("ABC","USD",401.));


    std::cout << "====================" << std::endl;
    return 0;
}
