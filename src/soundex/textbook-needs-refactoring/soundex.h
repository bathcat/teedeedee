#ifndef SOUNDEX_H_
#define SOUNDEX_H_

#include <string>

namespace soundex
{

   namespace internal
   {

      char toUpper(char c)
      {
         return std::toupper(c);
      }

      bool isVowel(char c)
      {
         return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
      }

      char toEncoding(char toEncode)
      {
         const char c = internal::toUpper(toEncode);
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


      std::string truncateWithPadding(const std::string &intermediate){
         if(intermediate.length() > 4){
            return intermediate.substr(0,4);
         }
         auto result = intermediate;
         for(auto i = intermediate.length(); i<4;i++){
            result += '0';
         }
         return result;
      }
      bool isSkippable(char c)
      {
         return c == 'Y' || c == 'H' || c == 'W';
      }
   }

   std::string encode(const std::string &original)
   {
      std::string result = "";
      result.append(1,internal::toUpper(original[0]));
      auto previous = internal::toEncoding(original[0]);
      for(int i =1;i<original.length();i++){
         auto current = internal::toEncoding(original[i]);
         if(current==previous){
            continue;
         }
         if(internal::isVowel(current)){
            previous = internal::toEncoding(original[i]);
            continue;
         }

         if(internal::isSkippable(current)){
            continue;
         }

         result.append(1,current);
         previous=current;
      }
      return internal::truncateWithPadding(result);
   }

}

#endif