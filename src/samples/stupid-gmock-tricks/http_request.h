#ifndef USER_H_
#define USER_H_

#include <string>

using namespace std;


namespace stupid_gmock_tricks
{
   struct HttpRequest{
     string token;
     string resource;
   };

}

#endif