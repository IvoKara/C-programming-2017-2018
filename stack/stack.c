#include "stack.h"
#include <stdlib.h>

Stack init(int initial_capacity)
{
  Stack new = {initial_capacity, 0};
  new.items = (float *) malloc(sizeof(float) * initial_capacity);
  return new;
}

void destroy(Stack *st)
{
  st->capacity = 0;
  st->count = 0;
  free(st->items);
}

int is_empty(Stack *st)
{
  return st->count == 0;
}

int is_full(Stack *st)
{
  return st->capacity - st->count < 1;
}

int resize(Stack *st)
{
  st->capacity *= 2;
  st->items = (float *) realloc(st->items, st->capacity);
  return st->capacity;
}
int push(Stack *st, float item)
{
  if(is_full(st))
  {
    resize(st);
  }
  st->items[st->count++] = item;
  return 1;
}

float top(Stack *st)
{
  return st->items[st->count-1];
}

float pop(Stack *st)
{
  float last = top(st);
  st->items[st->count--] = 0;
  return last;
}

Stack copy(Stack *src)
{
  Stack c = init(src->capacity);
  c.count = src->count;
  for(int i = 0; i < src->count; i++)
    c.items[i] = src->items[i];
  return c;
}
