#include <stdio.h>
#include "insertion_sort.h"

void insertion_sort(int *arr, int size)
{
	for(int i = 0; i < size; i++)
	{
		for(int j = i; j > 0; j--)
		{
				if(arr[j] < arr[j-1])
				{
					arr[j] = arr[j] ^ arr[j-1];
					arr[j-1] = arr[j] ^ arr[j-1];
					arr[j] = arr[j] ^ arr[j-1];
				}
		}
	}
}
