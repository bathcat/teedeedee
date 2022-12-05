#ifndef PRODUCT_H_
#define PRODUCT_H_

#include <string>

using namespace std;


namespace dependencies
{
   struct Product{
     string name;
     string description;
     int id;
   };

}

#endif