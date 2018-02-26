#include<stdio.h>
#include<stdlib.h>

int restore_data(int data1, int xor);

int main(int argc, char **argv)
{
	printf("%d\n", restore_data(10,13));
	return 0;
}

int restore_data(int data1, int xor)
{
	return data1 ^ xor;
}
