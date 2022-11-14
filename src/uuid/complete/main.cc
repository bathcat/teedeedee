#include <iostream>
#include "uuid.h"

const std::string usage = R"(
# Uuid

Command-line application to generate a new UUID
)";

int main(const int argc, const char **argv)
{
    if (argc > 1)
    {
        std::cout << usage << std::endl;
        return 0;
    }

    std::cout << uuid::generateUUID() << std::endl;

    return 0;
}
