#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int *random()
{
	static int arr[10];
	
	srand(time(0));
	
	for(int i = 0; i < 10; i++)
		arr[i] = rand() % 100;
	
	return arr;
}

int main(int argc, char **argv)
{
	int *ptr;
	ptr = random();
	for(int i = 0; i < 10; i++)
		printf("%d ", *(ptr + i));
	return 0;
}
