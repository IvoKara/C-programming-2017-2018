#include <stdio.h>
#include <stdlib.h>

struct wood_t
{
	float height;
	float width;
	float length;
	float price;
};

int can_fit(struct wood_t in_store, struct wood_t wanted);

int main()
{
	struct wood_t in_store = {10.0, 2.54, 1.5, 20.0};
	struct wood_t wanted = {11, 3, 1.5};
	printf("%d\n", can_fit(in_store, wanted));
	return 0;
}

int can_fit(struct wood_t in_store, struct wood_t wanted)
{
	if(in_store.height <= wanted.height && in_store.width <= wanted.width && in_store.length <= wanted.length)
		return 1;
	return -1;
}
