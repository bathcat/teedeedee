#ifndef DRAWING_CONTEXT_H_
#define DRAWING_CONTEXT_H_


namespace canvas
{
   template <class T>
   class DrawingContext
   {
   public:
      DrawingContext(T &turtle) : turtle(turtle) {}

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

   private:
      T &turtle;
   };

}

#endif