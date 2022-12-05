#ifndef NAIVE_SERVICE_GATEWAY_H_
#define NAIVE_SERVICE_GATEWAY_H_

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

   class NaiveServiceGateway
   {
   private:
      ConsoleLogger _logger = ConsoleLogger("Default");
      UserController _userController = UserController(_logger);
      ProductController _productController = ProductController(_logger);
      CustomerController _customerController = CustomerController(_logger);
      AuthenticationController _authenticationController = AuthenticationController(_logger);

   public:
      NaiveServiceGateway() {}

      string route(HttpRequest &request)
      {
         return "xyz";
      }
   };

}

#endif