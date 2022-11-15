#ifndef UUID_H_
#define UUID_H_

#include <string>
#include <limits>
#include <unistd.h>

namespace uuid
{
   
   // Only *somewhat* faithful to UUID as described here:
   //     https://en.wikipedia.org/wiki/Universally_unique_identifier
   //
   namespace internal
   {
      unsigned int getLowBits(unsigned long i)
      {
         return i & 0xffffffff;
      }

      unsigned short getMiddleBits(unsigned long i){
         return (i >> 24) & 0xffff ;
      }

      unsigned short getHighBits(unsigned long i){
         return i >> 48;
      }

      unsigned short getVersion(){
         return 4;
      }

      unsigned long getNodeID(){
         return gethostid();
      }

   }

   std::string generateUUID()
   {
      return "4d7508c6-0f70-47c3-aa3e-d4ea5f6be5ed";
   }

}

#endif