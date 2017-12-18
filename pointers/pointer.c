#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int main(int argc, char **argv)
{
	int a;
	float b;
	void *ptr;
	ptr = &a;
	*(int *)ptr = 4;
	printf("%d\n", a);
	ptr = &b;
	*(float *)ptr = 3.5;
	printf("%.2f", b);
	return 0;
}
