#include <stdio.h>

// Write a C program which reads values from stdin until EOF is reached, and then
// prints to stdout the most frequently occuring value.
//
// For example, if the input given was:
//   1 1 2 3 5
// Your program should print:
//   1
// as this was the most frequently occuring number -- it appeared twice.
//
// If there is a tie for the most frequent value, your program should print the
// largest value that is tied for most frequent.
//
// For example, if the input given was:
//   $ ./q3
//   1 2 1 2 1 2
// Your program should print:
//   2
// as this is the largest most frequently occuring number -- both 1 and 2 appeared
// three times, and 2 is the largest number.
//
// You can assume there will be no more than 100,000 numbers given.
//
// You can assume that all of the values will be between -100000 and 100000.
#define MAX_LEN 100000
#define NUM_MAX 100000
#define NUM_MIN -100000
int nums[NUM_MAX - NUM_MIN + 1] = {0};

int main(int argc, char *argv[]) {
  int num;
  while (scanf("%d", &num) == 1) {
    nums[num - NUM_MIN] ++;
  }

  // Assume there's definitely input
  int i = NUM_MAX - NUM_MIN;
  int curr_max_num = NUM_MIN - 1;
  int curr_max_count = 0;
  while (i >= 0) {
    if (nums[i] > curr_max_count) {
      curr_max_count = nums[i];
      curr_max_num = i + NUM_MIN;
    }
    i--;
  }

  printf("%d\n", curr_max_num);
}
