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
    std::map<std::string, Position> _positions;

  public:
    Portfolio()
    {
    }
    void deposit(Position p)
    {
      if (_positions.contains(p.symbol()))
      {
        _positions.insert_or_assign(p.symbol(), p.add(p));
        return;
      }
      _positions.insert_or_assign(p.symbol(), p);
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
      // std::map<std::string, Position> ps;
      // ps.insert(_positions.begin(),_positions.end());
      // return ps;
      return _positions;
    }
  };

}

#endif