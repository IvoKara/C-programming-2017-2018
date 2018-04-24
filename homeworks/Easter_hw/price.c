#include <stdio.h>
#include <stdlib.h>

float price(float amount, float price_per_kg);

int main(int argc, char **argv)
{
	int n = atoi(argv[1]);
	for (int i = 0; i < n; i++)
	{
		int curr_index = i + 2;
		printf("%f\n", price(atof(argv[curr_index+n]),atof(argv[curr_index])));
	}
	return 0;
}

float price(float amount, float price_per_kg)
{
	return amount*price_per_kg;
}
