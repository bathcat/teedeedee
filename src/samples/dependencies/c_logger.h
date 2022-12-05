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
      {logger.info(message)} -> std::same_as<void>;
      {logger.debug(message)} -> std::same_as<void>;
      {logger.error(message)} -> std::same_as<void>;
      {logger.warn(message)} -> std::same_as<void>;
   };

}

#endif