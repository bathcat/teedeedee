#include <iostream>
#include "fizz_buzz.h"
using namespace std;


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


int main(const int argc, const char**argv) {
    if(argc > 1){
        std::cout << usage << std::endl;
        return 0;
    }

    for(int i=1;i<101;i++){
        std::cout << getMessage(i) << std::endl;
    }
    return 0;
}
