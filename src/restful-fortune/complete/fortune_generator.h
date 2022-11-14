#ifndef FORTUNE_GENERATOR_H_
#define FORTUNE_GENERATOR_H_

#include <string>
#include "http_client.h"
#include "nlohmann/json.hpp"

namespace fortune
{
   class FortuneGenerator
   {
   private:
      HttpClient& httpClient;

   public:
      FortuneGenerator(HttpClient& client)
         :httpClient(client)
      {

      }

      std::string getFortune()
      {
         const auto response = httpClient.Get("http://numbersapi.com/random/trivia?json");
         if(response.status != 200){
            return "[Error getting fortune. Try again later.]";
         }
         const auto json = nlohmann::json::parse(response.body);

         return json["text"];
      }
   };

}

#endif