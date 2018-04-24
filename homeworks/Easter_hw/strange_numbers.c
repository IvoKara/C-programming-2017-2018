#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_strange(char *number, int k);
int my_pow(int n, int k);

int main(int argc, char **argv)
{
	for(int i = 1; i < argc; i+=2)
	{
		printf("%s --> ", argv[i]);
		int t = is_strange(argv[i], atoi(argv[i+1]));
		if(t == -1)
			printf(" don't have\n");
		else
			printf(" = %s * %d\n", argv[i], t);
	}

	return 0;
}

int is_strange(char *number, int k)
{
	long int big_integer = 0;
	for(int i = 0; i < strlen(number); i++)
	{
		big_integer += my_pow(number[i] - '0', k);
		k++;
	}
	printf("%ld", big_integer);
	float t = (float)big_integer/atoi(number);
	if(t == (int)t)
		return t;
	return -1;
}

int my_pow(int n, int k)
{
	int resault = n;
	for(int i = 1; i < k; i++)
		resault *= n;
	return resault;
}
