#ifndef _stack_h
#define _stack_h

/* Basic Stack that can hold 10 items */
struct Stack {
  int items[10];
  int top;
};

struct Stack *create_Stack();
void destroy_Stack(struct Stack *stack);
int pop(struct Stack *stack);
void push(struct Stack *stack, int item);
int is_empty(struct Stack *stack);

#endif
