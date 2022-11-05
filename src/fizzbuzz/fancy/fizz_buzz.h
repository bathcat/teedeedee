#ifndef FIZZBUZZ_H_
#define FIZZBUZZ_H_

#include <string>

const std::string getMessage(unsigned short i){
    if(i>100){
        throw std::invalid_argument( "received negative value" );
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


#endif