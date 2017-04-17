/*
  Regular expression is quite useful in real life
  in this question, you will be implementing a subset
  of regular expression utility, including: |, .

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
    ab|cd|ef
    matches: "abdf", "abef", "acdf", "acef"
  2. ., any letter matches .
  eg:
    a.
    matches: 'aa', 'ab', 'ac' ...
  3. the pattern should match the whole line (which is not the case
  for normal RegExp)
  NOTE:
    Assumption: all lines to match contains only letters and spaces
*/
int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
