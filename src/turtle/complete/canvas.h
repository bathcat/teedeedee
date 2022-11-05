#ifndef CANVAS_H_
#define CANVAS_H_

#include <iostream>
#include <memory>
#include "turtle.h"

class Canvas
{
public:
   Canvas(Turtle &turtle) : turtle(turtle) {}

   void DrawRectangle(int x, int y, unsigned int w, unsigned int h)
   {
      turtle.PenUp();
      turtle.GoTo(x, y);
      turtle.PenDown();

      turtle.PointTo(90);
      turtle.Forward(w);

      turtle.Turn(90);
      turtle.Forward(h);

      turtle.Turn(90);
      turtle.Forward(w);

      turtle.Turn(90);
      turtle.Forward(h);
   }

private:
   Turtle &turtle;
};

#endif