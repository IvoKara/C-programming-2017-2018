#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct person_t{int age; char name[20];};

typedef struct person_t Person;

int main(int argc, char **argv)
{
	Person *someone = (Person *) malloc(sizeof(Person));
	someone -> age = 16;
	strcpy(someone -> name, "Ivo");
	printf("%d, %s", someone-> age, someone -> name);
	free(someone);
	someone = NULL;
	free(someone);
	return 0;
}
