#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int sum(int a, int b)
{
	return a+b;
}

int main(int argc, char **argv)
{
	int (*func_ptr)(int,int);
	func_ptr = sum;
	// same as funct_ptr = &sum;
	printf("%d\n", func_ptr(4,6));
	return 0;
}
