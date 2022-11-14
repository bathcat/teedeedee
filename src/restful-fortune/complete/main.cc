#include <iostream>
#include <string>

#include "http_client_adapter.h"
#include "fortune_generator.h"


const std::string usage = R"(
Fortune
Lorem ipsum.....
)";

using namespace fortune;

int main(const int argc, const char**argv) {

    if(argc > 1){
        std::cout << usage << std::endl;
        return 0;
    }
    HttpClientAdapter httpClient;
    FortuneGenerator fortuneGenerator(httpClient);
    
    std::cout << fortuneGenerator.getFortune() << std::endl;
    
    return 0;
}
