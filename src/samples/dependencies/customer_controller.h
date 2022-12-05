#ifndef CUSTOMER_CONTROLLER_H_
#define CUSTOMER_CONTROLLER_H_

#include <string>


using namespace std;


namespace dependencies
{
   struct Customer{
     string login;
     string surname;
     int id;
   };


   template <class Tlogger>
   class CustomerController
   {
      private:
      int _nextID;
      Tlogger &_logger;
   public:
      CustomerController(Tlogger &logger,int nextID = 1000) 
      :_nextID(nextID),
      _logger(logger) {}

      Customer CreateNew(string login, string surname)
      {
        if (login == "")
        {
            throw std::invalid_argument("Login can't be empty");
        }

         Customer p;
         p.login=login;
         p.surname=surname;
         p.id = _nextID++;

         _logger.Info("Customer created!");
         return p;
      }


   };

}

#endif