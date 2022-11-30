#ifndef UUID_H_
#define UUID_H_

#include <string>
#include <limits>
#include <unistd.h>
#include <bitset>
#include <sstream>

namespace uuid
{

   // Only *somewhat* faithful to UUID as described here:
   //     https://en.wikipedia.org/wiki/Universally_unique_identifier
   //
   namespace internal
   {
      template <size_t sLeft, size_t sRight>
      std::bitset<sLeft + sRight> concat(const std::bitset<sLeft> &left, const std::bitset<sRight> &right)
      {
         std::bitset<sLeft + sRight> combined;
         for (size_t i = 0; i < sRight; i++)
         {
            combined[i] = right[i];
         }

         for (size_t i = 0; i < sLeft; i++)
         {
            combined[i + sRight] = left[i];
         }
         return combined;
      }

      template <size_t sPart, size_t sWhole>
      std::bitset<sPart> slice(const std::bitset<sWhole> &whole, const size_t offset)
      {
         std::bitset<sPart> part;
         for (size_t i = 0; i < sPart; i++)
         {
            part[i] = whole[i + offset];
         }

         return part;
      }

      char toHexDigit(const std::bitset<4> &bits)
      {
         std::stringstream writer;
         writer << std::hex << bits.to_ulong();
         return writer.str()[0];
      }

      unsigned int getLowBits(unsigned long i)
      {
         return i & 0xffffffff;
      }

      unsigned short getMiddleBits(unsigned long i)
      {
         return (i >> 24) & 0xffff;
      }

      unsigned short getHighBits(unsigned long i)
      {
         return i >> 48;
      }

      unsigned short getVersion()
      {
         return 4;
      }

      unsigned long getNodeID()
      {
         return gethostid();
      }

   }

   std::string generateUUID()
   {
      return "4d7508c6-0f70-47c3-aa3e-d4ea5f6be5ed";
   }

}

#endif