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

   class NaiveServiceGateway
   {
   private:
      Logger &_logger;
      UserController &_userController;
      ProductController &_productController;
      CustomerController &_customerController;
      AuthenticationController &_authenticationController;

   public:
      NaiveServiceGateway(
          Logger &logger,
          UserController &userController,
          ProductController &productController,
          CustomerController &customerController,
          AuthenticationController &authenticationController) : _logger(logger),
                                                                _userController(userController),
                                                                _productController(productController),
                                                                _customerController(customerController),
                                                                _authenticationController(authenticationController) {}

      string route(HttpRequest &request)
      {
         return "xyz";
      }
   };

}

#endif