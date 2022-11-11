#ifndef C_TURTLE_H_
#define C_TURTLE_H_

#include <concepts>

namespace canvas
{
   template <typename T>
   concept CTurtle = requires(T t, int i)
   {
      {t.PenUp()} -> std::same_as<void>;
      { t.PenDown() } -> std::same_as<void>;
      {t.Forward(i)} -> std::same_as<void>;
      {t.Turn(i)}->std::same_as<void>;
      {t.GoTo(i,i)}->std::same_as<void>;
      {t.GetX()} -> std::convertible_to<int>;
      {t.GetY()} -> std::convertible_to<int>;
      {t.TurnTo(i)} -> std::same_as<void>;
   };

}

#endif