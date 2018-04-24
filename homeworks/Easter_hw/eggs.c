#include <stdio.h>
#include <stdlib.h>

int sum(float *arr, int size);

int main()
{
	int index = 0;
	int capacity = 10;
	float *arr = (float *) malloc(sizeof(float) * capacity);
	while(1)
	{
		if(index == capacity)
		{
			capacity *= 2;
			arr = (float *) realloc(arr, sizeof(float) * capacity);
		}
		scanf("%f", &arr[index++]);
		char c = getchar();
		if(c == '\n')
			break;
	}
	printf("%.2f hours needed", arr[0]/sum(arr, index));
	free(arr);
	return 0;
}

int sum(float *arr, int size)
{
	float sum = 0;
	for(int i = 1; i < size; i++)
		sum += arr[i];
	return sum;
}
