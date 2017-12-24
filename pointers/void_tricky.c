#include<stdio.h>
#include<string.h>

void max(void *arr, int size, char type)
{
	switch(type)
	{
		case 'f':
			for(int i = 0; i < size; i++)
				printf("%f", *(float *)(arr + i));
			break;
		case 'c':
			for(int i = 0; i < size; i++)
				printf("%f", *(char *)(arr + i));
			break;
	}
}

int main()
{
	float arr[] = {};
	return 0;
}
