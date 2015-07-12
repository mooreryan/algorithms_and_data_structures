/* 12 July 2015 */

#include <stdio.h>

int linear_search(const int arr[], const int size, const int val)
{
  int i = 0;

  for (i = 0; i < size; i++) {
    if (arr[i] == val) {
      return i;
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

  printf( "Should be -1: %d\n", linear_search(a1, 0, val) );
  printf( "Should be -1: %d\n", linear_search(a2, 1, val) );
  printf( "Should be 0: %d\n",  linear_search(a3, 1, val) );
  printf( "Should be 2: %d\n",  linear_search(a4, 4, val) );
  printf( "Should be -1: %d\n", linear_search(a5, 5, val) );

  return 0;
}
