#ifndef SOUNDEX_H_
#define SOUNDEX_H_

#include <string>
#include <ranges>
#include <string_view>
//#include <range/v3/action/unique.hpp>
//#include <range/v3/view/all.hpp>
#include <range/v3/view/transform.hpp>
#include <range/v3/view/take.hpp>
#include <range/v3/view/drop.hpp>
#include <range/v3/view/repeat.hpp>
#include <range/v3/view/concat.hpp>
#include <range/v3/view/filter.hpp>
#include <range/v3/view/unique.hpp>

namespace soundex
{
   // using std::ranges::unique;
   //  using std::views::drop;
   //  using std::views::filter;
   //  using std::views::join;
   //  using std::views::single;
   //  using std::views::take;
   // using std::views::transform;
   //  using std::views::repeat;
   //  using ranges::actions::unique;
   using ranges::views::concat;
   using ranges::views::drop;
   using ranges::views::repeat;
   using ranges::views::take;
   using ranges::views::transform;
   using ranges::views::filter;
   using ranges::views::unique;

   using std::string;

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

   auto getPrefix(string original)
   {
      return original | transform(toUpper) | take(1);
   }

   auto getBody(string original)
   {
      return original | transform(toUpper)
                      | drop(1)
                      | filter(isNonSkippable)
                      | transform(toEncoding)
                      | unique
                      | filter(isNonVowel);
   }

   auto getPadding()
   {
      return repeat('0');
   }

   string encode(string original)
   {
      auto sequence = concat(
              getPrefix(original),
              getBody(original),
              getPadding()
           ) | take(4);
      
      string result;
      std::ranges::copy(
          sequence,
          std::back_inserter(result));

      return result;
   }

}

#endif