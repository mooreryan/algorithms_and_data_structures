/* 12 July 2015 */
/* A little Stack that can dynamically resize */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "stack.h"

struct Stack *create_Stack()
{
  struct Stack *stack = malloc(sizeof(struct Stack));
  assert(stack != NULL);

  const int default_size = 10;
  stack->items = malloc(sizeof(int) * default_size);
  assert(stack->items != NULL);

  stack->size = default_size;
  stack->top = -1;

  return stack;
}

void destroy_Stack(struct Stack *stack)
{
  assert(stack != NULL);
  assert(stack->items != NULL);

  free(stack->items);
  free(stack);
}

/* Double the size of the stack */
void double_size(struct Stack *stack)
{
  stack->size *= 2;
  int *tmp = realloc(stack->items, sizeof(int) * stack->size);
  assert(tmp != NULL);

  stack->items = tmp;
  assert(stack->items != NULL);
}

/* Returns 999 and keeps going if the stack is empty */
int pop(struct Stack *stack)
{
  assert(stack->top >= -1 && stack->top < stack->size);

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
  assert(stack->top >= -1 && stack->top <= stack->size);
  stack->top += 1;

  if (stack->top == stack->size) {
    double_size(stack);

    // add item
    stack->items[stack->top] = item;

  } else {
    stack->items[stack->top] = item;
  }

  assert(stack->top <= stack->size);
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

int peek(struct Stack *stack)
{
  assert(stack->top >= -1 && stack->top < stack->size);

  if (stack->top == -1) {
    return 999;
  }

  return stack->items[stack->top];
}

void print_Stack(struct Stack *stack)
{
  printf("Stack Info: is-empty?: %d, top: %d, top item: %d, size %d\n\n",
         is_empty(stack), stack->top, peek(stack), stack->size);

}
