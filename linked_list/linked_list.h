#ifndef __LIST_H__
#define __LIST_H__

struct node_t
{
  int value;
  struct node_t *next;
};

struct list_t
{
  struct node_t *head;
};

typedef struct list_t llist;
typedef struct node_t node;

llist init_list(int);
void destroy_list(llist *);
int insert(llist *, int, int);
int append(llist *, int);
int remove_fo(llist *, int);
int remove_range(llist *,int, int);
int get(llist *, int);
int size(llist *);
llist copy(llist *);

void print_list(llist *);

node *get_node(llist *, int);
#endif
