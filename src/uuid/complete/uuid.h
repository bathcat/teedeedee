#ifndef UUID_H_
#define UUID_H_

#include <string>
#include <limits>

namespace uuid
{
   // TODO: Think about int_t and the like

   namespace internal
   {
      unsigned int getLowBits(unsigned long i)
      {
         return i & 0xffffffff;
      }

      unsigned short getMiddleBits(unsigned long i){
         return (i >> 24) & 0xffff ;
      }

   }

   std::string generateUUID()
   {
      return "f80fadd8-5031-4a06-b069-88c1c3b14da2";
   }

}

#endif