#include <iostream>
#include <string>
#include "fortune.h"

#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"
#include "nlohmann/json.hpp"

const std::string usage = R"(
Fortune
Lorem ipsum.....
)";

int main(const int argc, const char **argv)
{

    if (argc > 1)
    {
        std::cout << usage << std::endl;
        return 0;
    }

    httplib::Client httpClient("http://numbersapi.com");
    const auto httpResponse = httpClient.Get("/random/trivia?json");
    std::cout << std::endl<< httpResponse.value().body << std::endl;
    return 0;
    const auto json = nlohmann::json::parse(httpResponse.value().body);

    std::cout << std::endl
              << json["text"] 
              << std::endl;

    return 0;
}
