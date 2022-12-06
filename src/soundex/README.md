# Soundex

## Summary
* [Soundex](https://en.wikipedia.org/wiki/Soundex) is a phontic algorithm designed to indexing personal names by sound, regardless of spelling
* Inspired by [Modern C++ Programming with Test-Driven Development](https://www.amazon.com/Modern-Programming-Test-Driven-Development-Better/dp/1937785483)
* Advantages:
  - Pre-defined spec
  - Multiple implementations possible

## Rules
1. Keep the first letter as-is
2. For everything else:
  - Drop characters **y**, **h**, **w**
  - Replace consonants with numbers (see next slide)
  - Drop repeats
  - Drop vowels
3. Truncate to 4 characters-- padding with 0s as necessary

### Substitutions

| Letter                 | Digit |
|------------------------|-------|
| b, f, p, v             | 1     |
| c, g, j, k, q, s, x, z | 2     |
| d, t                   | 3     |
| l                      | 4     |
| m, n                   | 5     |
| r                      | 6     |
| y, h, w                | (Skip)|
