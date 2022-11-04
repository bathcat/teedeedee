#ifndef CANVAS_H_
#define CANVAS_H_

#include <iostream>
#include <memory>
#include "turtle.h"

class Canvas
{
public:
   Canvas(Turtle& turtle) : turtle(turtle) {}

   void DrawRectangle(unsigned int x, unsigned int y, unsigned int w, unsigned int h)
   {
      turtle.PenDown();
      std::cout << std::endl << "drawing............" << std::endl << std::endl;
   }

private:
   Turtle& turtle;
};

#endif