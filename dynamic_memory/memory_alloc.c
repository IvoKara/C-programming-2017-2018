#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int *make_arr(int);

int main(int argc, char **argv)
{
	int *testy = make_arr(10);
	for(int i = 0; i < 10; i++)
		printf("%d ", testy[i]);
	return 0;
}

int *make_arr(int n)
{
	int *arr = (int *) malloc(sizeof(int) * n);
	for(int i = 0; i < n; i++)
		arr[i] = i + 1;
	return arr;
}
