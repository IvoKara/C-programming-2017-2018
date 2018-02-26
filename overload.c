#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int sum(int a, int b)
{
	return a+b;
}

float sum(float a, float b)
{
	return a+b;
}

int main(int argc, char **argv)
{
	printf("%d\n", sum(14, 16));
	printf("%.2f\n", sum(12.34, 17,45));
	return 0;
}
