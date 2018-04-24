#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct game_t
{
	int id;
	float price;
	char country[4];
};

int is_game_available(struct game_t game, char country[4]);
int how_many_available(struct game_t games[10], char country[4]);

int main()
{
	struct game_t games[10];
	strcpy(games[0].country, "BG");
	strcpy(games[1].country, "US");
	strcpy(games[2].country, "UK");
	strcpy(games[3].country, "BG");

	printf("%d\n", how_many_available(games,"BG"));
	return 0;
}

int is_game_available(struct game_t game, char country[4])
{
	return !strcmp(game.country, country);
}

int how_many_available(struct game_t games[10], char country[4])
{
	int count = 0;
	for(int i = 0; i < 10; i++)
	{
		count += is_game_available(games[i], country);
	}
	return count;
}
