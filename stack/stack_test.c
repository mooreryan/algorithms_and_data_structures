/* 12 July 2015 */
/* A little Stack with a fixed size of 10 integer elements. */

#include <stdio.h>
#include "stack.h"

int main(int argc, char *argv[])
{
  struct Stack *stack = create_Stack();

  printf("Is the stack empty? %d (should be 1)\n", is_empty(stack));
  printf("The top of the stack: %d (should be -1)\n", stack->top);

  push(stack, 12);
  printf("The top of the stack: %d (should be 0)\n", stack->top);

  push(stack, 7);
  printf("The top of the stack: %d (should be 1)\n", stack->top);

  push(stack, -3);
  printf("The top of the stack: %d (should be 2)\n", stack->top);

  printf("Is the stack empty? %d (should be 0)\n", is_empty(stack));

  printf("Pop the stack: %d (should be -3)\n", pop(stack));
  printf("The top of the stack: %d (should be 1)\n", stack->top);

  printf("Pop the stack: %d (should be 7)\n", pop(stack));
  printf("The top of the stack: %d (should be 0)\n", stack->top);

  printf("Pop the stack: %d (should be 12)\n", pop(stack));
  printf("The top of the stack: %d (should be -1)\n", stack->top);

  printf("Now try to pop on an empty array!\n");
  printf("Pop the stack: %d (should be error (999))\n", pop(stack));

  printf("Is the stack empty? %d (should be 1)\n", is_empty(stack));

  int i = 0;
  int size = 10;
  puts("staring the loop");
  for (i = 0; i <= size; i++) {
    push(stack, i*10);
    printf("The top of the stack: %d\n", stack->top);
    printf("The top item is: %d\n", stack->items[stack->top]);
  }
  puts("the loop is done");

  printf("The top of the stack: %d (should be 9)\n", stack->top);

  destroy_Stack(stack);

  return 0;
}
