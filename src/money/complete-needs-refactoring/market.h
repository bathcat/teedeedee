#ifndef MARKET_H_
#define MARKET_H_

#include <string>
#include <vector>
#include "position.h"
#include "converter.h"
#include "portfolio.h"

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

    const Position consolidate(Position &original, const std::string inTermsOf)
    {
      for (auto c : converters)
      {
        if (c.symbolFrom() == original.symbol() && c.symbolTo() == inTermsOf)
        {
          return c.convert(original.quantity());
        }
      }
      return original;
    }

    
    const Portfolio consolidate(Portfolio &original, const std::string inTermsOf)
    {
      Portfolio consolidatedPortfolio;

      for(auto &[symbol, position] : original._positions){
        auto consolidatedPosition = consolidate(position, inTermsOf);
        consolidatedPortfolio.deposit(consolidatedPosition);
      }

      return consolidatedPortfolio;
    }


  };

}

#endif