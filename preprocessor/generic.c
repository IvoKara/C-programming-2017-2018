#include<stdio.h>
#include<stdlib.h>
#include"mul.h"

#define MAX_ELEM 10
//GENERIG FUNCTOINS
#define MUL_BY_TWO(a) (a * 2)
#define _MUL_BY_TWO(a) ((a) * 2)
#define MAX_OF_TWO(a ,b)(a > b ? a : b)


int main(int argc, char **argv)
{
	printf("%d\n", MUL_BY_TWO(5 + 6)); // 5 + 6 * 2
	printf("%.2f == %.2f\n", MUL_BY_TWO((5.6 + 6.1)), _MUL_BY_TWO(5.6 + 6.1));
	printf("%d\n", multiply(2, 5));
	printf("%d\n", sum(4, 5));
	return 0;
}
