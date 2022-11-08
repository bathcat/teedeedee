#include <iostream>


const std::string usage = R"(
Fortune
Lorem ipsum.....
)";


int main(const int argc, const char**argv) {

    if(argc > 1){
        std::cout << usage << std::endl;
        return 0;
    }

    std::cout << "You will meet a tall dark stranger." << std::endl;
    
    return 0;
}
