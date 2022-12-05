#ifndef MATH_H_
#define MATH_H_

#include <vector>
#include <functional>

using namespace std;


namespace dependencies
{
   int add(int left, int right) {
     return left + right;
   }

   float getAverage(vector<int> numbers,function<int(int,int)> _add){
      int total = 0;
      for(auto n:numbers){
        total = _add(total,n);
      }
      return total / numbers.size();
   }

  float getAverage(vector<int> const & numbers){
      return getAverage(numbers, [](int l,int r){return l + r;});
   }

   class Math{

    public:
    int add(int left, int right){
      return left + right;
    }

    int subtract(int left, int right){
      return left - right;
    }

    int multiply(int left, int right){
      return left * right;
    }

    int divide(int left, int right){
      return left / right;
    }

   };

}

#endif