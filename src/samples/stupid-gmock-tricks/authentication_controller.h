#ifndef AUTHENTICATION_CONTROLLER_H_
#define AUTHENTICATION_CONTROLLER_H_

#include <string>
#include <stdexcept>

#include "logger.h"

using namespace std;

namespace stupid_gmock_tricks
{

   class AuthenticationController
   {
   private:
      Logger &_logger;

   public:
      AuthenticationController(Logger &logger) : _logger(logger)
      {
         logger.Debug("[[[[ Doing AuthenticationController stuff. ]]]]");
      }
   };

}

#endif