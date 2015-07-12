/* 11 July 2005 */

#include <stdio.h>

void selection_sort(int arr[], const int size)
{
  int i, j, swap;

  /* Invariant: arr[0..i] should always be sorted */
  for (i = 0; i < size; i++) {
    int current_smallest = i;

    /* Invariant: arr[current_smallest] <= arr[n] for all n in [j..size-1] */
    for (j = i + 1; j < size; j++) {
      if (arr[j] < arr[current_smallest]) {
        // note the index of smallest
        current_smallest = j;
      }
    }

    if (i != current_smallest) {
      swap = arr[i];
      arr[i] = arr[current_smallest];
      arr[current_smallest] = swap;
    }
  }
}

void print_array(int arr[], const int size)
{
  if (size == 0) {
    printf("[ ]\n");
  } else {
    int i = 0;
    printf("[ ");
    for (i = 0; i < size; i++) {
      printf("%d ", arr[i]);
    }
    printf("]\n");
  }
}

int main(int argc, char *argv[])
{
  int a1[] = { };
  int a2[] = { 1 };
  int a3[] = { 1, 2 };
  int a4[] = { 2, 1 };
  int a5[] = { 5, -3, 4 };
  int a6[] = { 3, 3, 3 };
  int a7[] = { -3, 6, 4, 6, 7, 2, 10 };

  int size = 0;

  selection_sort(a1, size);
  printf( "[ ] : ");
  print_array(a1, size);

  size = 1;
  selection_sort(a2, size);
  printf( "[ 1 ] : ");
  print_array(a2, size);

  size = 2;
  selection_sort(a3, size);
  printf( "[ 1 2 ] : ");
  print_array(a3, size);

  selection_sort(a4, size);
  printf( "[ 1 2 ] : ");
  print_array(a4, size);

  size = 3;
  selection_sort(a5, size);
  printf( "[ -3 4 5 ] : ");
  print_array(a5, size);

  selection_sort(a6, size);
  printf( "[ 3 3 3 ] : ");
  print_array(a6, size);

  size = 7;
  selection_sort(a7, size);
  printf( "[ -3 2 4 6 6 7 10 ] : ");
  print_array(a7, size);

  return 0;
}
