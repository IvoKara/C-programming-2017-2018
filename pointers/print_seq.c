#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int print_seq(int *start, int *end)
{
	for(int *i = start; i < end; i++)
		printf("%d ", *i);
	return end - start;
}

int main(int argc, char **argv)
{
	int var;
	int lol;
	printf("%p\n", (void *)&var);
	printf("%p\n", (void *)&lol);
	printf("%d", &lol - &var);
	print_seq(&var, &lol);
	return 0;
}
