#include <stdio.h>
#include <stdlib.h>

int swap_bits(int n, int position1, int position2);

int main()
{
	int n, position1, position2;
	scanf("%d", &n);
	scanf("%d", &position1);
	scanf("%d", &position2);
	printf("%d\n",swap_bits(n, position1, position2));
	return 0;
}

int swap_bits(int n, int position1, int position2)
{
	int mask1 = 1 << (position1 - 1);
	int mask2 = 1 << (position2 - 1);
	int a = n & mask1;
	int b = n & mask2;
	if(!a == !b)
		return n;
	if(a == 0)
		return ((n | mask1) ^ mask2);
	else
		return ((n | mask2) ^ mask1);

}
