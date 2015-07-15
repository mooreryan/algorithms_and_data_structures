/* 12 July 2015 */
/* Test the stack! */

#include <stdio.h>
#include "stack.h"

int main(int argc, char *argv[])
{
  struct Stack *stack = create_Stack();

  print_Stack(stack);

  push(stack, 12);
  print_Stack(stack);

  push(stack, 7);
  print_Stack(stack);

  push(stack, -3);
  print_Stack(stack);

  printf("Pop the stack: %d (should be -3)\n", pop(stack));
  print_Stack(stack);

  printf("Pop the stack: %d (should be 7)\n", pop(stack));
  print_Stack(stack);

  printf("Pop the stack: %d (should be 12)\n", pop(stack));
  print_Stack(stack);

  printf("Now try to pop on an empty array!\n");
  printf("Pop the stack: %d (should be error (999))\n", pop(stack));
  print_Stack(stack);

  int i = 0;
  int size = 10;
  printf("\n\nLooping\n");
  for (i = 0; i <= size; i++) {
    printf("pushing %d\n", i*10);
    push(stack, i*10);
    print_Stack(stack);
  }
  printf("Finished looping\n\n");

  push(stack, 1234);
  print_Stack(stack);

  destroy_Stack(stack);

  return 0;
}
