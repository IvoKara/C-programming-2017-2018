#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main()
{
	//fprintf(stderr, "What is hapenning\n");
	llist new = init_list(5);
	insert(&new, 14, 0);
	append(&new, 9);
	append(&new, 123);
	append(&new, 1111);
	append(&new, 66);
	llist cpy = copy(&new);
	remove_range(&new, 2, size(&new));
	print_list(&new);
	print_list(&cpy);
	destroy_list(&new);
	destroy_list(&cpy);
	return 0;
}
