#ifndef LOGGER_H_
#define LOGGER_H_

#include <string>

using namespace std;


namespace dependencies
{
   class Logger
   {
   public:
      virtual ~Logger() {}
      virtual void Debug(string message) = 0;
      virtual void Info(string message) = 0;
      virtual void Warn(string message) = 0;
      virtual void Error(string message) = 0;
   };

}

#endif