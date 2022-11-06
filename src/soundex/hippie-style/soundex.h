#ifndef SOUNDEX_H_
#define SOUNDEX_H_

#include <string>

//TODO: Use the CPP2023 implementations when we upgrade.
#include <range/v3/view/transform.hpp>
#include <range/v3/view/take.hpp>
#include <range/v3/view/drop.hpp>
#include <range/v3/view/repeat.hpp>
#include <range/v3/view/concat.hpp>
#include <range/v3/view/filter.hpp>
#include <range/v3/view/unique.hpp>
#include <range/v3/range/conversion.hpp>

namespace soundex
{
   using ranges::to;
   using ranges::views::concat;
   using ranges::views::drop;
   using ranges::views::filter;
   using ranges::views::repeat;
   using ranges::views::take;
   using ranges::views::transform;
   using ranges::views::unique;

   using std::string;

   namespace internal
   {

      bool isSkippable(char c)
      {
         return c == 'Y' || c == 'H' || c == 'W';
      }
      bool isNonSkippable(char c)
      {
         return !isSkippable(c);
      }

      bool isVowel(char c)
      {
         return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
      }

      bool isNonVowel(char c)
      {
         return !isVowel(c);
      }

      char toEncoding(char c)
      {
         if (c == 'B' || c == 'F' || c == 'P' || c == 'V')
         {
            return '1';
         }

         if (c == 'C' || c == 'G' || c == 'J' || c == 'K' || c == 'Q' || c == 'S' || c == 'X' || c == 'Z')
         {
            return '2';
         }

         if (c == 'D' || c == 'T')
         {
            return '3';
         }

         if (c == 'L')
         {
            return '4';
         }

         if (c == 'M' || c == 'N')
         {
            return '5';
         }

         if (c == 'R')
         {
            return '6';
         }
         return c;
      }

      char toUpper(char c)
      {
         return std::toupper(c);
      }

      auto getPrefix(const string& string original)
      {
         return original | transform(toUpper) | take(1);
      }

      auto getBody(const string& string original)
      {
         return original | transform(toUpper) | filter(isNonSkippable) | transform(toEncoding) | unique | drop(1) | filter(isNonVowel);
      }

      auto getPadding()
      {
         return repeat('0');
      }
   }

   string encode(const string& original)
   {
      using namespace internal;
      return concat(getPrefix(original), getBody(original), getPadding()) |
             take(4) | to<std::string>();
   }

}

#endif