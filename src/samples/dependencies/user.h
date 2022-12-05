#ifndef USER_H_
#define USER_H_

#include <string>

using namespace std;


namespace dependencies
{
   struct User{
     string givenName;
     string surname;
     int id;
   };

}

#endif