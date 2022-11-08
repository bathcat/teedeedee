#include <iostream>
#include "fortune.h"

#include "http_client.h"
#include "nlohmann/json.hpp"

const std::string usage = R"(
Fortune
Lorem ipsum.....
)";


int main(const int argc, const char**argv) {

    if(argc > 1){
        std::cout << usage << std::endl;
        return 0;
    }

    httplib::Client cli("http://api.kanye.rest");
    const auto res = cli.Get("/");    
    const auto jsn = nlohmann::json::parse(res.value().body);

    std::cout << "Body:" << jsn["quote"] << std::endl;
    
    return 0;
}
