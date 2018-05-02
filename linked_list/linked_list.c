#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>
llist init_list(int start_value)
{
  llist l;
  l.head = (node *) malloc(sizeof(node));
  l.head->value = start_value;
  l.head->next = NULL;
  return l;
}

static void free_items(llist *l, int start, int end)
{
  node *before = get_node(l, start-1);
  node *start_node = before->next;
  node *end_node = get_node(l, end);
  while(start_node != end_node)
  {
    before->next = start_node->next;
    free(start_node);
    start_node = before->next;
  }
}

void destroy_list(llist *l)
{
  remove_range(l, 0, size(l));
  free(l->head);
}

void print_list(llist *l)
{
  node *current = l->head;
  while(current != NULL)
  {
    printf("%d ", current->value);
    current = current->next;
  }
  printf("\n");
}

static int insert_begin(llist *l, int value)
{
  node *new = (node *) malloc(sizeof(node));
  new->value = l->head->value;
  l->head->value = value;
  new->next = l->head->next;
  l->head->next = new;
  return 1;
}

int insert(llist *l, int value, int pos)
{
  if(pos > size(l) || pos < 0)
    return 0;

  if(pos == 0)
  {
    return insert_begin(l, value);
  }
  else
  {
    node *new = (node *) malloc(sizeof(node));
    new->value = value;
    node *before = l->head;
    int index = 1;
    while(index < pos)
    {
      before = before->next;
      index++;
    }
    new->next = before->next;
    before->next = new;
  }
  return 1;
}

int append(llist *l, int value)
{
  return insert(l, value, size(l));
}

int size(llist *l)
{
  int count = 0;
  node *current = l->head;
  while(current != NULL)
  {
    current = current->next;
    count++;
  }
  return count;
}

static int remove_before(llist *l)
{
  node *next = l->head->next;
  if(next == NULL)
  {
    l->head->value = 0;
    return -1;
  }
  l->head->value = next->value;
  l->head->next = next->next;
  free(next);
  return 1;
}

int remove_fo(llist *l, int first_occurance)
{
  node *current = l->head;
  if(current->value == first_occurance)
    return remove_before(l);
  node *next = current->next;
  while(next != NULL)
  {
    if(next->value == first_occurance)
    {
      current->next = next->next;
      free(next);
      return 1;
    }
    current = next;
    next = next->next;
  }
  return 0;
}

int remove_range(llist *l, int start, int end)
{
  if(start == 0)
  {
    if(end == size(l))
    {
      append(l, 0);
    }
    node *end_node = get_node(l, end);
    l->head->value = end_node->value;
    end++;
    start++;
  }
  free_items(l, start, end);
  return 1;
}

node *get_node(llist *l, int index)
{
  node *current = l->head;
  int count = 0;
  while(count < index)
  {
    current = current->next;
    count++;
  }
  return current;
}

int get(llist *l, int index)
{
  node *current = get_node(l, index);
  return current->value;
}

llist copy(llist *l)
{
  llist c = init_list(l->head->value);
  node *current = l->head->next;
  while(current != NULL)
  {
    append(&c, current->value);
    current = current->next;
  }
  return c;
}
