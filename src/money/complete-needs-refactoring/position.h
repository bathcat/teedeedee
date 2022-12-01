#ifndef POSITION_H_
#define POSITION_H_

#include <string>;

namespace money
{

  class Position
  {
  private:
    int _quantity;
    std::string _symbol;

  public:
    Position(std::string symbol, int quantity)
    {
      _quantity = quantity;
      _symbol = symbol;
    }

    // Position(Position original){
    //   _quantity=original.quantity();
    //   _symbol=original.symbol();
    // }

    const int quantity()
    {
      return _quantity;
    }

    const std::string symbol()
    {
      return _symbol;
    }

    const Position add(Position &right)
    {
      if (right.symbol() != _symbol)
      {
        throw std::invalid_argument("Wrong currency!");
      }

      return Position(_symbol, _quantity + right.quantity());
    }
  };

}

#endif