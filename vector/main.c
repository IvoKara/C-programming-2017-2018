#include <stdio.h>
#include <stdlib.h>
#include "my_vector.h"

int main()
{
	struct vector_t v = init();
	add_last(&v, 3);
	add_last(&v, 2);
	add_last(&v, 12);
	add_last(&v, 43);
	add_last(&v, 11);
	printf("last elem: %d\n", pop(&v));
	printf("%d\n", full(&v));
	printf("%d\n", first(&v));
	add_first(&v, 15);
	for(int i = 0; i < v.lenght; i++)
		printf("%d ", v.arr[i]);
	destroy(&v);
	//add_last(&v, 1);
	return 0;
}
