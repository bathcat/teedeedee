#ifndef FORTUNE_GENERATOR_H_
#define FORTUNE_GENERATOR_H_

#include <string>
#include "http_client.h"

namespace fortune
{
   class FortuneGenerator
   {
   private:
      HttpClient &client;

   public:
      FortuneGenerator(HttpClient &client)
      {
         client = client;
      }

      std::string getFortune()
      {
         return "You will meet a short, pale stranger."
      }
   }

}

#endif