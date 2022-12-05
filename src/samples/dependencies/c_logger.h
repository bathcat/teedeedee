#ifndef C_LOGGER_H_
#define C_LOGGER_H_

#include <concepts>
#include <string>

using namespace std;

namespace dependencies
{
   template <typename Tlogger>
   concept CLogger = requires(Tlogger logger, string message)
   {
      {logger.Info(message)} -> std::same_as<void>;
      {logger.Debug(message)} -> std::same_as<void>;
      {logger.Error(message)} -> std::same_as<void>;
      {logger.Warn(message)} -> std::same_as<void>;
   };

}

#endif