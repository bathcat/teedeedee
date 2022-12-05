#ifndef CUSTOMER_CONTROLLER_H_
#define CUSTOMER_CONTROLLER_H_

#include <string>
#include <stdexcept>
#include "logger.h"
#include "http_response.h"

using namespace std;

namespace stupid_gmock_tricks
{
   struct Customer
   {
      string login;
      string surname;
      int id;
   };

   class CustomerController
   {
   private:
      int _nextID;
      Logger &_logger;

   public:
      CustomerController(Logger &logger, int nextID = 1000)
          : _nextID(nextID),
            _logger(logger)
      {
         logger.Debug("[[[[ Doing CustomerController stuff. ]]]]");
      }

      HttpResponse CreateNew(string login, string surname)
      {
         if (login == "")
         {
            throw std::invalid_argument("Login can't be empty");
         }

         Customer p;
         p.login = login;
         p.surname = surname;
         p.id = _nextID++;
         //TODO: Persist
         
         _logger.Info("Customer created!");

         return HttpResponse(200,"{result:'ok'}");
      }
   };

}

#endif