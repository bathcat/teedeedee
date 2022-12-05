#ifndef PRODUCT_CONTROLLER_H_
#define PRODUCT_CONTROLLER_H_

#include <string>
#include <stdexcept>

#include "logger.h"
#include "http_response.h"

using namespace std;

namespace stupid_gmock_tricks
{

   struct Product
   {
      string name;
      string description;
      int id;
   };

   class ProductController
   {
   private:
      int _nextID;
      Logger &_logger;

   public:
      ProductController(Logger &logger, int nextID = 1000)
          : _nextID(nextID),
            _logger(logger)
      {
         logger.Debug("[[[[ Doing ProductController stuff. ]]]]");
      }

      HttpResponse CreateNew(string name, string description)
      {
         if (name == "")
         {
            throw std::invalid_argument("Name can't be empty");
         }

         Product p;
         p.name = name;
         p.description = description;
         p.id = _nextID++;

         _logger.Info("Product created!");
         return HttpResponse(200, "{result:'ok'}");
      }
   };

}

#endif