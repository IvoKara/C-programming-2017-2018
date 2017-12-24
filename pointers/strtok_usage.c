#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int word_count(char *str);

int main(int argc, char **argv)
{
	for(int i = 1; i < argc; i++)
		word_count(argv[i]);
	return 0;
}

int word_count(char *str)
{
	int count = 0;
	char *ptr;
	ptr = strtok(str, " ");
	while(ptr != NULL)
	{
		count++;
		printf("%s -> %d\n", ptr, count);
		ptr = strtok(NULL, " ");
	}
	return count;
}
