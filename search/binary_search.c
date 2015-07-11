/* 10 July 2015 */

/* Here is a nice explanation on variants https://goo.gl/3rAEYV */

#include <stdio.h>

/* Search for val in arr (a sorted array). Return index of location,
   -1 otherwise. */
int binary_search(const int arr[], const int size, const int val)
{
  int lower = 0;
  int upper = size - 1;
  int i = 0;

  /* Invariant: If val is a member of arr, say arr[i], then
     lower <= i <= upper. */
  while (lower <= upper) {
    i = lower + (upper - lower) / 2;

      if (val == arr[i]) {
        return i;
      } else if (val < arr[i]) {
        upper = i - 1;
      } else { // arr[i] < val
        lower = i + 1;
      }
  }

  return -1;
}

int main(int argc, char *argv[])
{
  int val = 5;
  int a1[] = { };
  int a2[] = { 1 };
  int a3[] = { 5 };
  int a4[] = { -1, 3, 5, 6 };
  int a5[] = { 1, 2, 3, 4, 10 };

  printf( "Should be -1: %d\n", binary_search(a1, 0, val) );
  printf( "Should be -1: %d\n", binary_search(a2, 1, val) );
  printf( "Should be 0: %d\n",  binary_search(a3, 1, val) );
  printf( "Should be 2: %d\n",  binary_search(a4, 4, val) );
  printf( "Should be -1: %d\n", binary_search(a5, 5, val) );

  return 0;
}
