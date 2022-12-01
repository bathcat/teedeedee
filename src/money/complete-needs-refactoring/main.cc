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
    Market market;
    market.addConverter(Converter("MSFT", "USD", 95.));
    market.addConverter(Converter("ABC", "USD", 401.));

    Portfolio original;
    original.deposit(Position("MSFT", 1000));
    original.deposit(Position("ABC", 200));

    auto cashedOut = market.consolidate(original, "USD");

    //

    std::cout << "====================" << std::endl;
    std::cout << "== Original ========" << std::endl;
    std::cout << "====================" << std::endl;

    original.report(std::cout);
    std::cout << std::endl;

    std::cout << "====================" << std::endl;
    std::cout << "== Cashed Out ======" << std::endl;
    std::cout << "====================" << std::endl;

    cashedOut.report(std::cout);
    std::cout << "====================" << std::endl
              << std::endl;

    return 0;
}
