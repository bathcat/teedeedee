#include <iostream>

using namespace std;


const std::string usage = R"(
Lorem ipsum

)";


int main(const int argc, const char**argv) {
    if(argc > 1){
        std::cout << usage << std::endl;
        return 0;
    }

    std::cout << "hello world" << std::endl;
    
    return 0;
}
