#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int sum(int a, int b)
{
	return a+b;
}

int mul(int a, int b)
{
	return a*b;
}

int abs_sub(int a, int b)
{
	return abs(a-b);
}

int main(int argc, char **argv)
{
	int (*func_ptr)(int,int);
	func_ptr = sum;
	// same as funct_ptr = &sum;
	printf("%d\n", func_ptr(4,6));
	int (*arr_func[3])(int, int) = {sum, mul, abs_sub};
	for(int i = 0; i < 3; i++)
		printf("%d ", arr_func[i](10, 7));
	return 0;
}
