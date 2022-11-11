#ifndef TURTLE_BASE_H_
#define TURTLE_BASE_H_

namespace canvas
{
   class TurtleBase
   {
   public:
      virtual ~TurtleBase() {}
      virtual void PenUp() = 0;
      virtual void PenDown() = 0;
      virtual void Forward(int distance) = 0;
      virtual void Turn(int degrees) = 0;
      virtual void GoTo(int x, int y) = 0;
      virtual int GetX() const = 0;
      virtual int GetY() const = 0;
      virtual void TurnTo(int degrees) = 0;
   };

}

#endif