/*
  Regular expression is quite useful in real life
  in this question, you will be implementing a subset
  of regular expression utility, including: |, ., [],
  ?, *, ^, $

  Regular expression is used to match a pattern inside
  a string.
  input: Two lines,
  line 1: RegExp
  line2: text to match
  output: 'YES' if the second line matches the pattern
  provided by the first line

  intro:
  1. |, the pipe notation means the character at the
  corresponding position can either be the letter on
  the left or the letter on the right(not the case in real RegExp):
  eg:
    ab|c
    matches: "ab" or "ac"
  2. ., any letter matches .
  eg:
    a.
    matches: 'aa', 'ab', 'ac' ...
  3. [], the letter at corresponding position can be any
  one of those within the square brackets:
  eg:
    a[bcde]g
    matches: "abg" or "acg" or "adg" or "aeg"
  4. ?: the letter on the left is optional for matching
  eg:
    ab?
    matcheds: "a" or "ab"
  5. *: the letter on the left is can occur 0 to infinitely many times
  for matching (exclude with ?)
  eg:
    ab*
    matcheds: "a" or "ab" or "abb" or "abbb" ...
  6, 7: ^, $ denotes the start and end of the line respectively
  eg:
    ^a
    matches: "a", "ab", "abc" but not: "bab", "ba"

    a$
    matches: "a", "ba", "bca" but not: "bab", "ab"

    ^a$
    only matches: "a"
  8. the pattern don't match the whole line unless explicitly denoted by ^, $
  eg:
    a
    matches: "askdjha", "ddddddadddddd", "a" ...
  9. Combined usage of multiple special characters can happen, all
  'letter' in the rules becomes 'letters or special control group'
  eg:
    a[bcd]*
    can match: "a", "ab", "ac", "abc", "adcd" ...
  NOTE:
    Assumption: all lines to match contains only letters and spaces
*/
int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
