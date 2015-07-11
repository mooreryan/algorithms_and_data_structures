/* 11 July 2015 */

#include <stdio.h>

void insertion_sort(int arr[], const int size)
{
  int i = 0;

  for (i = 1; i < size; i++) {

    int j = 0;
    // stop either when j is zero, or when arr[j] <= arr[j+1] because
    // of the invariant
    for (j = i - 1; j >= 0 && arr[j] > arr[j+1]; j--) {
      // switch them!
      int larger_num = arr[j];
      arr[j] = arr[j+1];
      arr[j+1] = larger_num;
    }

    /* Invariant: arr[0..i] is sorted */
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

  int size = 0;

  insertion_sort(a1, size);
  printf( "[ ] : ");
  print_array(a1, size);

  size = 1;
  insertion_sort(a2, size);
  printf( "[ 1 ] : ");
  print_array(a2, size);

  size = 2;
  insertion_sort(a3, size);
  printf( "[ 1 2 ] : ");
  print_array(a3, size);

  insertion_sort(a4, size);
  printf( "[ 1 2 ] : ");
  print_array(a4, size);

  size = 3;
  insertion_sort(a5, size);
  printf( "[ -3 4 5 ] : ");
  print_array(a5, size);

  insertion_sort(a6, size);
  printf( "[ 3 3 3 ] : ");
  print_array(a6, size);

  return 0;
}
