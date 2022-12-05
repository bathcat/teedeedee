#ifndef CONSOLE_LOGGER_H_
#define CONSOLE_LOGGER_H_

#include <string>
#include <iostream>
#include "logger.h"

using namespace std;

namespace stupid_gmock_tricks
{
   class ConsoleLogger : public Logger
   {
      private:
      string _name;
   public:
      ConsoleLogger(string name):_name(name){}
      ~ConsoleLogger() {}
      void Debug(string message)
      {
         std::cout << "Debug: " << message << std::endl;
      }
      void Info(string message)
      {
         std::cout << "Debug: " << message << std::endl;
      }
      void Warn(string message)
      {
         std::cout << "Debug: " << message << std::endl;
      }
      void Error(string message)
      {
         std::cout << "Debug: " << message << std::endl;
      }
   };

}

#endif