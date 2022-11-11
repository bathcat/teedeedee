#ifndef CANVAS_H_
#define CANVAS_H_

#include <iostream>
#include "third_party_library_turtle.h"

namespace canvas
{

   class DrawingContext
   {

   private:
      third_party_library::Turtle &turtle;

   public:
      DrawingContext(third_party_library::Turtle &turtle) : turtle(turtle) {}

      void DrawRectangle(int x, int y, unsigned int w, unsigned int h)
      {
         turtle.PenUp();
         turtle.GoTo(x, y);
         turtle.TurnTo(0);
         turtle.PenDown();

         turtle.Turn(90);
         turtle.Forward(w);

         turtle.Turn(90);
         turtle.Forward(h);

         turtle.Turn(90);
         turtle.Forward(w);

         turtle.Turn(90);
         turtle.Forward(h);
      }

   };

}

#endif