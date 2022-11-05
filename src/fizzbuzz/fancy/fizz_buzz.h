#ifndef FIZZBUZZ_H_
#define FIZZBUZZ_H_

#include <string>
#include <iostream>
#include <vector>

namespace fizzbuzz
{

    const std::string getMessage(unsigned short i)
    {
        if (i > 100)
        {
            throw std::invalid_argument("received negative value");
        }
        const auto multiple_of_3 = i % 3 == 0;
        const auto multiple_of_5 = i % 5 == 0;

        if (multiple_of_3 && multiple_of_5)
        {
            return "FizzBuzz";
        }

        if (multiple_of_3)
        {
            return "Fizz";
        }

        if (multiple_of_5)
        {
            return "Buzz";
        }

        return std::to_string(i);
    }

    const std::string usage = R"(
    Fizz Buzz
    Surprisingly, lots of professional programmers can't really program.
    This is a classic interview question for sussing-out the non-skilled.

    Here it is:
    Write a program that prints the numbers from 1 to 100. But for
    multiples of three print “Fizz” instead of the number and for the
    multiples of five print “Buzz”. For numbers which are multiples
    of both three and five print “FizzBuzz”.

    Requirements
    * Implement getMessage method.
    * Write specs to document and test.
    * Write the correct output--described above-- to the console.
    )";

    std::vector<std::string> getAllMessages()
    {
        std::vector<std::string> messages;
        for (int i = 0; i < 100; i++)
        {
            messages.push_back(getMessage(i + 1));
        }
        return messages;
    }

    std::string getOutput(const int argc)
    {
        std::string result = "";
        if (argc > 1)
        {
            result = usage;
        }
        else
        {
            for (auto message : getAllMessages())
            {
                result += message + "\n";
            }
        }

        return result;
    }

}

#endif