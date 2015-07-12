/* 12 July 2015 */
/* A little Stack with a fixed size of 10 integer elements. */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "stack.h"


struct Stack *create_Stack()
{
  struct Stack *stack = malloc(sizeof(struct Stack));
  assert( stack != NULL );

  stack->top = -1;

  return stack;
}

void destroy_Stack(struct Stack *stack)
{
  assert(stack != NULL);

  free(stack);
}

/* Returns 999 and keeps going if the stack is empty */
int pop(struct Stack *stack)
{
  assert(stack->top >= -1 && stack->top < 10);

  if (stack->top == -1) {
    fprintf(stderr, "Error: The stack is empty!\n");
    return 999;
  }

  int item = stack->items[stack->top];
  stack->top -= 1;

  return item;
}

/* When the Stack is full, print an error and keep going */
void push(struct Stack *stack, int item)
{
  assert(stack->top >= -1);

  if (stack->top >= 9) {
    fprintf(stderr, "Error: the stack is full. Not pushing!\n");
  } else {
    stack->top += 1;

    stack->items[stack->top] = item;
  }
}

/* Returns 1 if the stack is empty, 0 if it is not */
int is_empty(struct Stack *stack)
{
  if (stack->top == -1) {
    return 1;
  } else {
    return 0;
  }
}
