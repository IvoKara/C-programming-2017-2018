#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct card_t {int num; float currency;};
struct human_t {char name[20]; struct card_t *card;};

int pay_with(struct human_t *person, float to_pay)
{
	if(person -> card -> currency >= to_pay)
	{
		person -> card -> currency -= to_pay;
		return 1;
	}
	else 
		return 0;
}

int main(int argc, char **argv)
{
	struct card_t card = {1235, 235.25};
	struct human_t h = {"Ivo", &card};
	pay_with(&h, 200);
	printf("%f\n", h.card -> currency);
	return 0;
}
