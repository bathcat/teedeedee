#ifndef PRODUCT_CONTROLLER_H_
#define PRODUCT_CONTROLLER_H_

#include <string>
#include "c_logger.h"
#include "product.h"
#include "console_logger.h"

using namespace std;


namespace dependencies
{

   template <class Tlogger>
   requires CLogger<Tlogger>
   class ProductController
   {
      private:
      int _nextID;
      Tlogger &_logger;
   public:
      ProductController(Tlogger &logger,int nextID = 1000) 
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

         _logger.Info("Product created!");
         return p;
      }


   };

}

#endif