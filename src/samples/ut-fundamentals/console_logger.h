#ifndef LOGGER_H_
#define LOGGER_H_

#include <string>
#include <iostream>
#include "logger.h"

using namespace std;


namespace utFundamentals
{
   class ConsoleLogger: public Logger
   {
   public:
       ~ConsoleLogger() {}
      void Debug(string message){
         std::out << "Debug: " << message << std::endl;
      }
      void Info(string message){
         std::out << "Debug: " << message << std::endl;
      }
      void Warning(string message){
         std::out << "Debug: " << message << std::endl;

      }
      void Error(string message){
         std::out << "Debug: " << message << std::endl;
      }
   };

}

#endif