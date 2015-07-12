/* 12 July 2015 */
/* A little Stack with a fixed size of 10 integer elements. */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/* Basic Stack that can hold 10 items */
struct Stack {
  int items[10];
  int top;
};

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
