#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char **argv)
{
	char *vector = (char *) malloc(4);
	memset(vector, 'a', 6);
	
	printf("%d\n", strlen(vector));
	//prezapiswa
	vector = (char *) realloc(vector, 6);
	free(vector);	
	vector = NULL;
	free(vector);	
	return 0;
}
