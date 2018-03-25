#include <stdio.h>
#include <stdlib.h>
#include "bitoper.h"

int count_ones(int n)
{
	int *byte = turn_to_bits(n);
	int count = 0;
	for (size_t i = 0; i < 32; i++)
	{
		if(byte[i] == 1)
			count++;
	}
	return count;
}

int *turn_to_bits(int n)
{
	int *byte = (int *) calloc(32, sizeof(int));
	if(n < 0)
	{
		byte[31] = 1;
		n *= -1;
	}

	int bit_index = 0;

	while(n != 0)
	{
		byte[bit_index++] = n % 2;
		n>>=1;
	}
	return byte;
}

void print_bits(int n)
{
	int *byte = turn_to_bits(n);
	printf("%d -> 0b", n);
	if(count_ones(n) == 0)
	{
		printf("0");
	}
	int found = 0;
	for(int i = 31; i >= 0; i--)
	{
		if(byte[i] == 1)
			found = 1;
		if(found)
			printf("%d", byte[i]);
	}
	printf(" (%d ones)\n", count_ones(n));
}
