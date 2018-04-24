#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

void print_items(Stack *st)
{
	for (int i = 0; i < st->count; i++)
		printf("%.2f ", st->items[i]);
	printf("\n");
}

int main()
{
	printf("Reverse Polish Notation: ");
	char rpn[31];
	fgets(rpn, 30, stdin);
	Stack st = init(2);
	float result;
	for(int i = 0; i < strlen(rpn) - 1; i+=2)
	{
		switch (rpn[i])
		 {
			case '+': result = pop(&st) + pop(&st); break;
			case '-': result = pop(&st); result = pop(&st) - result; break;
			case '*': result = pop(&st) * pop(&st); break;
			case '/': result = pop(&st); result = pop(&st) / result; break;
			default: result = rpn[i] - '0'; break;
		}
		push(&st, result);
		//print_items(&st);
	}
	printf("%.2f\n", st.items[0]);
	destroy(&st);
	return 0;
}
