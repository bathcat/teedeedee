#ifndef CONVERTER_H_
#define CONVERTER_H_

#include <string>
#include "position.h"

namespace money
{

  class Converter
  {
  private:
    std::string _symbolFrom;
    std::string _symbolTo;
    float _rate;

  public:
    Converter(std::string symbolFrom, std::string symbolTo, float rate)
    {
      _symbolFrom = symbolFrom;
      _symbolTo = symbolTo;
      _rate = rate;
    }

    const std::string symbolTo(){
      return _symbolTo;
    }

    const std::string symbolFrom(){
      return _symbolFrom;
    }

    Position convert(const int quantity)
    {
      return Position(_symbolTo, quantity*_rate);
    }
  };

}

#endif