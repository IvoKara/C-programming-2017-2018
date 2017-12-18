#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct human_t {int married; float salary;};

void raise_salary(struct human_t *person)
{
	if(person -> married)
		person -> salary += person -> salary*0.25;
	else
		person -> salary += person -> salary*0.5;
}

int main(int argc, char **argv)
{
	struct human_t testy = {1, 30};
	raise_salary(&testy);
	printf("%d %f\n", testy.married, testy.salary);
	return 0;
}
