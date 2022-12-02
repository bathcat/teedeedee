#ifndef PORTFOLIO_H_
#define PORTFOLIO_H_

#include <string>
#include <map>
#include "position.h"
#include <ostream>

namespace money
{

  class Portfolio
  {
  private:

  public:
    std::map<std::string, Position> _positions;
    Portfolio()
    {
    }
    void deposit(Position p)
    {
      auto newPosition = _positions.contains(p.symbol()) 
      ? p.add(_positions.at(p.symbol()))
      : p;
      _positions.insert_or_assign(p.symbol(), newPosition);
    }

    const void report(std::ostream &stream)
    {
      for (auto &[symbol, position] : _positions)
      {
        stream << symbol << ": " << position.quantity() << std::endl;
      }
    }

    std::map<std::string, Position> positions()
    {
      std::map<std::string, Position> ps;
      ps.insert(_positions.begin(),_positions.end());
      return ps;
    }
  };

}

#endif