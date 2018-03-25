#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char **argv)
{
	char src[10] = "Ivo";
	char dest[20] = "Karaneshev";
	memcpy(dest, src, 3);
	printf("%s", dest);
	return 0;
}
