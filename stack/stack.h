/* 12 July 2015 */
/* A little Stack that can dynamically resize */

#ifndef _stack_h
#define _stack_h

struct Stack {
  int *items;
  int size;
  int top;
};

struct Stack *create_Stack();
void destroy_Stack(struct Stack *stack);
void double_size(struct Stack *stack);
int pop(struct Stack *stack);
void push(struct Stack *stack, int item);
int is_empty(struct Stack *stack);
int peek(struct Stack *stack);
void print_Stack(struct Stack *stack);

#endif
