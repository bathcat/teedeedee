#ifndef PRODUCT_CONTROLLER_H_
#define PRODUCT_CONTROLLER_H_

#include <string>
#include "c_logger.h"
#include "product.h"
#include "console_logger.h"

using namespace std;


namespace dependencies
{

   template <class T>
   requires CLogger<T>
   class ProductController
   {
      private:
      int _nextID;
      T &_logger;
   public:
      ProductController(Logger &logger,int nextID = 1000) 
      :_nextID(nextID),
      _logger(logger) {}

      Product CreateNew(string name, string description)
      {
        if (name == "")
        {
            throw std::invalid_argument("Name can't be empty");
        }

         Product p;
         p.name=name;
         p.description=description;
         p.id = _nextID++;
         return p;
      }


   };

}

#endif