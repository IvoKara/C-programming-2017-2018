#include <stdio.h>
#include "shellsort.h"
#include "insertion_sort.h"

int main(int argc, char **argv)
{
	int arr[] = {1, 4, 34, 54, 10, 33};
	shell_sort(arr, 6);
	//insertion_sort(arr, 6);
	for(int i = 0; i < 6; i++)
		printf("%d ", arr[i]);
	return 0;
}
