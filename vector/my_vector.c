#include "my_vector.h"
#include <stdlib.h>

struct vector_t init()
{
  struct vector_t v;
  v.capacity = 2;
  v.lenght = 0;
  v.arr = (int *) calloc(sizeof(int), v.capacity);
  return v;
}

void add_last(struct vector_t *v, int item)
{
  if(v->lenght == v->capacity)
  {
    v->capacity *= 2;
    v->arr = (int *) realloc(v->arr, sizeof(int) * v->capacity);
  }
  v->arr[v->lenght++] = item;
}

int last(struct vector_t *v)
{
  return v->arr[v->lenght - 1];
}

int pop(struct vector_t *v)
{
  int poped = last(v);
  v->lenght--;
  //free(&v->arr[v->lenght]);
  return poped;
}

int empty(struct vector_t* v)
{
  return v->lenght == 0;
}

int full(struct vector_t* v)
{
  return !empty(v);
}

void destroy(struct vector_t* v)
{
  v->lenght = v->capacity = 0;
  free(v->arr);
}

int at(struct vector_t* v, int index)
{
  return v->arr[index];
}

int first(struct vector_t* v)
{
  return at(v, 0);
}

int insert_at(struct vector_t* v, int index, int item)
{
  if(v->lenght == v->capacity)
  {
    v->capacity *= 2;
    v->arr = (int *) realloc(v->arr, sizeof(int) * v->capacity);
  }
  int temp;
  v->arr[v->lenght] = 0;
  v->lenght++;
  for(int i = index; i < v->lenght; i++)
  {
    temp = v->arr[i];
    v->arr[i] = item;
    item = temp;
  }
  return 1;
}

int add_first(struct vector_t* v, int item)
{
  return insert_at(v,0,item);
}
