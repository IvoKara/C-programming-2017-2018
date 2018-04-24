#ifndef MY_VECTOR
#define MY_VECTOR

struct vector_t
{
	int capacity;
	int lenght;
	int *arr;
};

struct vector_t init();
void add_last(struct vector_t*, int);
int last(struct vector_t*);
int pop(struct vector_t*);
int empty(struct vector_t*);
int full(struct vector_t*);
void destroy(struct vector_t*);
int at(struct vector_t*, int);
int first(struct vector_t*);
int insert_at(struct vector_t*, int, int);
int add_first(struct vector_t*, int);

#endif
