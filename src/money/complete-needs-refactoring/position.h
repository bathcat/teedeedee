#ifndef POSITION_H_
#define POSITION_H_

#include <string>

namespace money
{

  class Position
  {
  private:
    int _quantity;
    std::string _symbol;

  public:
    Position(const std::string symbol, const int quantity)
    :_quantity(quantity),
    _symbol(symbol)
    {

    }

    const int quantity()
    {
      return _quantity;
    }

    const std::string symbol()
    {
      return _symbol;
    }

    const Position add(Position &other)
    {
      if (other.symbol() != symbol())
      {
        throw std::invalid_argument("Wrong currency!");
      }

      return Position(symbol(), quantity() + other.quantity());
    }
  };

}

#endif