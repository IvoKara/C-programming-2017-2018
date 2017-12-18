#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void print_address(void *arr, int size, char id);

int main(int argc, char **argv)
{
	int arr[] = {1 , 2, 3};
	print_address(arr, 3, 'i');
	print_address("abc", 3, 'c');
	return 0;
}

void print_address(void *arr, int size, char id)
{

	switch(id)
	{
		case 'i':
			for(int i = 0; i < size; i++)
				printf("%p\n", (void *)((int *)arr+i));
			break;
			case 'c':
				for(int i = 0; i < size; i++)
					printf("%p\n", (void *)((char *)arr+i));
				break;
	}
}

