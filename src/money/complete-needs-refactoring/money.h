#ifndef MONEY_H_
#define MONEY_H_

namespace money
{
  class Money
  {
  private:
    int _quantity;

  public:
    Money(int quantity) : _quantity(quantity) {}

    const int quantity()
    {
      return _quantity;
    }

    const Money add(Money &right)
    {
      return Money(_quantity + right.quantity());
    }
  };

}

#endif