#include<stdio.h>
#include<stdlib.h>

int new_pressed(int old_state, int new_state);
int released(int old_state, int new_state);

int main(int argc, char **argv)
{
	int old = 10;           // 1010
  int new = 13;           // 1101
  new_pressed(old, new);  // 0101
  released(old, new);     // 0010
	return 0;
}

int released(int old_state, int new_state)
{
	return (old_state ^ new_state) & old_state;
}

int new_pressed(int old_state, int new_state)
{
	return (old_state ^ new_state) & new_state;
}
