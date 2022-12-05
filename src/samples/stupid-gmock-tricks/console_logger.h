#ifndef CONSOLE_LOGGER_H_
#define CONSOLE_LOGGER_H_

#include <string>
#include <iostream>
#include "logger.h"

using namespace std;


namespace stupid_gmock_tricks
{
   class ConsoleLogger: public Logger
   {
   public:
       ~ConsoleLogger() {}
      void Debug(string message){
         std::cout << "Debug: " << message << std::endl;
      }
      void Info(string message){
         std::cout << "Debug: " << message << std::endl;
      }
      void Warning(string message){
         std::cout << "Debug: " << message << std::endl;

      }
      void Error(string message){
         std::cout << "Debug: " << message << std::endl;
      }
   };

}

#endif