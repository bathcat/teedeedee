#ifndef MARKET_H_
#define MARKET_H_

#include <string>
#include <vector>
#include "position.h"
#include "converter.h"

namespace money
{

  class Market
  {
  private:
    std::vector<Converter> converters;

  public:
    Market()
    {
    }

    void addConverter(Converter c)
    {
      converters.push_back(c);
    }

    const Position consolidate(Position &position, const std::string inTermsOf)
    {
      for (auto c : converters)
      {
        if (c.symbolFrom() == position.symbol() && c.symbolTo() == inTermsOf)
        {
          return c.convert(position.quantity());
        }
      }
      return position;
    }
  };


}

#endif