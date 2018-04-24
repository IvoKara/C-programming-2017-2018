#include <stdio.h>
#include <stdlib.h>

void ajust_item(int *item);
void ajust_arr(int *arr, int size);

int main()
{
	int arr[10] = {1, 2, 3, 12, 20, 11, 25, 10, 13, 6};
	ajust_arr(arr, 10);
	for(int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	return 0;
}

void ajust_item(int *item)
{
	if(*item % 2 == 0)
		*item *= 2;
	else
		*item *= 3;
}

void ajust_arr(int *arr, int size)
{
	for(int i = 0; i < size; i++)
		ajust_item(&arr[i]);
}
