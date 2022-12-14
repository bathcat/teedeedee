#ifndef USER_CONTROLLER_H_
#define USER_CONTROLLER_H_

#include <string>
#include <stdexcept>

#include "logger.h"
#include "http_response.h"

using namespace std;

namespace stupid_gmock_tricks
{
   struct User
   {
      string givenName;
      string surname;
      int id;
   };

   class UserController
   {
   private:
      int _nextID;
      Logger &_logger;

   public:
      UserController(Logger &logger, int nextID = 1000)
          : _nextID(nextID),
            _logger(logger)
      {
         logger.Debug("[[[[ Doing UserController stuff. ]]]]");
      }

      HttpResponse CreateNew(string givenName, string surname)
      {
         if (givenName == "")
         {
            throw std::invalid_argument("GivenName can't be empty");
         }

         User u;
         u.givenName = givenName;
         u.surname = surname;
         u.id = _nextID++;

         return HttpResponse(200,"{result:'ok'}");
      }
   };

}

#endif