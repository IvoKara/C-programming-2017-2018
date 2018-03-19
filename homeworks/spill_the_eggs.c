#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define max_width 1000

struct str_t {int width; int whole_height; char line[max_width];};

void find  (struct str_t *vessel);
void print (struct str_t *vessel);

void fill  (struct str_t *vessel, int row, int col, char *to_fill);
void up    (struct str_t *vessel, int row, int col, char *to_fill);
void left  (struct str_t *vessel, int row, int col, char *to_fill);
void right (struct str_t *vessel, int row, int col, char *to_fill);
void down  (struct str_t *vessel, int row, int col, char *to_fill);

int main(int argc, char **argv)
{
	int height, width;
	
	scanf("%d %d", &width, &height); 
	getchar();
	
	char input[width + 2];
	struct str_t vessel[height];
	
	for(int i = 0; i < height; i++)
	{
		fgets(input, width + 1, stdin);
		getchar();
		strcpy(vessel[i].line, input);
	}
	
	vessel[0].width = width;
	vessel[0].whole_height = height;
	
	find(vessel);
	print(vessel);
	
	return 0;
}

void find(struct str_t *vessel)
{
	char to_fill;
	for(int i = 0; i < vessel[0].whole_height; i++)
	{
		for(int j = 0; j < vessel[0].width; j++)
		{			
			if(vessel[i].line[j] == 'O')
			{
				to_fill = 'O';
				fill(vessel, i, j, &to_fill);
			}
			else if(vessel[i].line[j] == '*')
			{
				to_fill = '*';
				fill(vessel, i, j, &to_fill);
			}
		}
	}
}

void fill(struct str_t *vessel, int row, int col, char *to_fill)
{
	up(vessel, row, col, to_fill);
	left(vessel, row, col, to_fill);
	right(vessel, row, col, to_fill);
	down(vessel, row, col, to_fill);
}

void up(struct str_t *vessel, int row, int col, char *to_fill)
{
	if(row > 0)  
	{	
		if(vessel[row - 1].line[col] != '#' && vessel[row - 1].line[col] != *to_fill)
		{
			// |'O' - '*'|
			if(abs(vessel[row - 1].line[col] - *to_fill) == 37)
			{
				*to_fill = '@';
				vessel[row].line[col] = '@';
			}
			vessel[row - 1].line[col] = *to_fill;
			fill(vessel, row - 1, col, to_fill);
		}
	}
}

void left(struct str_t *vessel, int row, int col, char *to_fill)
{
	if(col > 0)  
	{	
		if(vessel[row].line[col - 1] != '#' && vessel[row].line[col - 1] != *to_fill)
		{
			// |'O' - '*'|
			if(abs(vessel[row].line[col - 1] - *to_fill) == 37)
			{
				*to_fill = '@';
				vessel[row].line[col] = '@';
			}
			vessel[row].line[col - 1] = *to_fill;
			fill(vessel, row, col - 1, to_fill);
		}
	}
}

void right(struct str_t *vessel, int row, int col, char *to_fill)
{
	if(col < vessel[0].width - 1)  
	{	
		if(vessel[row].line[col + 1] != '#' && vessel[row].line[col + 1] != *to_fill)
		{
			// |'O' - '*'|
			if(abs(vessel[row].line[col + 1] - *to_fill) == 37)
			{
				*to_fill = '@';
				vessel[row].line[col] = '@';
			}
			vessel[row].line[col + 1] = *to_fill;
			fill(vessel, row, col + 1, to_fill);
		}
	}
}

void down(struct str_t *vessel, int row, int col, char *to_fill)
{
	if(row < vessel[0].whole_height - 1)  
	{	
		if(vessel[row + 1].line[col] != '#' && vessel[row + 1].line[col] != *to_fill)
		{
			// |'O' - '*'|
			if(abs(vessel[row + 1].line[col] - *to_fill) == 37)
			{
				*to_fill = '@';
				vessel[row].line[col] = '@';
			}
			vessel[row + 1].line[col] = *to_fill;
			fill(vessel, row + 1, col, to_fill);
		}
	}
}

void print(struct str_t *vessel)
{
	for(int i = 0; i < vessel[0].whole_height; i++)
		printf("%s\n", vessel[i].line);
}
