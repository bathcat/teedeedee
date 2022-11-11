#ifndef THIRD_PARTY_LIBRARY_TURTLE_H_
#define THIRD_PARTY_LIBRARY_TURTLE_H_

#include <iostream>

namespace third_party_library
{
   class Turtle
   {
   private:
      int x;
      int y;
      bool isPenDown;

   public:
      void PenUp()
      {
         isPenDown = false;
      }

      void PenDown()
      {
         isPenDown = true;
      }

      void Forward(int distance)
      {
         std::cout << "{{Forward}}" << std::endl;
      };

      void Turn(int degrees)
      {
         std::cout << "{{Turn}}" << std::endl;
      }

      void GoTo(int x, int y)
      {
         std::cout << "{{GoTo}}" << std::endl;
      }

      int GetX() const
      {
         std::cout << "{{GetX}}" << std::endl;
         return this->x;
      }

      int GetY() const
      {
         std::cout << "{{GetY}}" << std::endl;
         return this->y;
      }

      void TurnTo(int degrees)
      {
         std::cout << "{{TurnTo}}" << std::endl;
      }
   };

}

#endif