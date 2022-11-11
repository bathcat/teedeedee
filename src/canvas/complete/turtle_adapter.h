#ifndef TURTLE_ADAPTER_H_
#define TURTLE_ADAPTER_H_

#include <iostream>
#include "third_party_library_turtle.h"
#include "turtle.h"

namespace canvas
{
   class TurtleAdapter : public canvas::Turtle
   {
   private:
      third_party_library::Turtle& wrappedTurtle;

   public:
      TurtleAdapter(third_party_library::Turtle& turtle):wrappedTurtle(turtle){}

      void PenUp()
      {
         wrappedTurtle.PenUp();
      }

      void PenDown()
      {
         wrappedTurtle.PenDown();
      }

      void Forward(int distance)
      {
         wrappedTurtle.Forward(distance);
      };

      void Turn(int degrees)
      {
         wrappedTurtle.Turn(degrees);
      }

      void GoTo(int x, int y)
      {
         wrappedTurtle.GoTo(x,y);
      }

      int GetX() const
      {
         return wrappedTurtle.GetX();
      }

      int GetY() const
      {
         return wrappedTurtle.GetY();
      }

      void TurnTo(int degrees)
      {
         wrappedTurtle.TurnTo(degrees);
      }
   };

}

#endif