#ifndef USER_CONTROLLER_H_
#define USER_CONTROLLER_H_

#include <string>
#include "logger.h"
#include "user.h"
#include "console_logger.h"

using namespace std;


namespace dependencies
{


   class UserController
   {
      private:
      int _nextID;
      Logger &_logger;
   public:
      UserController(Logger &logger,int nextID = 1000) 
      :_nextID(nextID),
      _logger(logger) {}

      User CreateNew(string givenName, string surname)
      {
        if (givenName == "")
        {
            throw std::invalid_argument("GivenName can't be empty");
        }

         User u;
         u.givenName=givenName;
         u.surname=surname;
         u.id = _nextID++;
         return u;
      }


   };

}

#endif