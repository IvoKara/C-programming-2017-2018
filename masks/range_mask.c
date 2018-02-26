#include<stdio.h>
#include<stdlib.h>

typedef unsigned char BYTE;

int main(int argc, char **argv)
{
	int low = 1, high = 3;
	BYTE mask = ~0;	
	mask <<= high - low + 1;
	mask = ~mask;
	mask <<= low;
	return 0;
}
