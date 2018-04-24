#ifndef __STACK_H__
#define __STACK_H__

//#define Stack struct stack_t

struct stack_t
{
  int capacity;
  int count;
  float *items;
};

typedef struct stack_t Stack;

Stack init(int);
void destroy(Stack *);
int push(Stack *, float);
float top(Stack *);
float pop(Stack *);
int resize(Stack*);
int is_full(Stack *);
int is_empty(Stack *);
Stack copy(Stack *);
#endif
