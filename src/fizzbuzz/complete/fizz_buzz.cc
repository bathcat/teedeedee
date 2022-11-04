#include "fizz_buzz.h"
#include <string>
#include <stdexcept>
using namespace std;

const string get_message(unsigned short i){
    if(i>100){
        throw invalid_argument( "received negative value" );
    }
    const auto multiple_of_3 = i%3==0;
    const auto multiple_of_5 = i%5==0;

    if(multiple_of_3 && multiple_of_5){
        return "FizzBuzz";
    }

    if(multiple_of_3){
        return "Fizz";
    }

    if(multiple_of_5){
        return "Buzz";
    }

    return std::to_string(i);
}
