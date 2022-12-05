#include <iostream>

const std::string usage = R"(
# Samples: UT Fundamentals

> Lorem ipsum dolor sit amet consectetur adipiscing elit, urna consequat felis 
> vehicula class ultricies mollis dictumst, aenean non a in donec nulla. Phasellus 
> ante pellentesque erat cum risus consequat imperdiet aliquam, integer placerat 
> et turpis mi eros nec lobortis taciti, vehicula nisl litora tellus ligula 
> porttitor metus. 


)";

int main(const int argc, const char **argv)
{
    if (argc > 1)
    {
        std::cout << usage << std::endl;
        return 0;
    }

    std::cout << "Doing stuff!" << std::endl;

    return 0;
}
