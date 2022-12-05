#ifndef SERVICE_GATEWAY_H_
#define SERVICE_GATEWAY_H_

#include <string>
#include "logger.h"
#include "console_logger.h"
#include "user_controller.h"
#include "http_request.h"
#include "product_controller.h"
#include "customer_controller.h"
#include "authentication_controller.h"

using namespace std;

namespace stupid_gmock_tricks
{
   bool contains(string subject, string target)
   {
      return subject.find(target) != std::string::npos;
   }

   class ServiceGateway
   {
   private:
      Logger &_logger;
      UserController &_userController;
      ProductController &_productController;
      CustomerController &_customerController;
      AuthenticationController &_authenticationController;

   public:
      ServiceGateway(
          Logger &logger,
          UserController &userController,
          ProductController &productController,
          CustomerController &customerController,
          AuthenticationController &authenticationController) : _logger(logger),
                                                                _userController(userController),
                                                                _productController(productController),
                                                                _customerController(customerController),
                                                                _authenticationController(authenticationController) {}

      string getController(const HttpRequest request)
      {
         if (contains(request.resource, "/customers"))
         {
            return "CustomerController";
         }
         if (contains(request.resource, "/users"))
         {
            return "UserController";
         }
         if (contains(request.resource, "/products"))
         {
            return "ProductController";
         }
         return "ErrorController";
      }
   };

}

#endif