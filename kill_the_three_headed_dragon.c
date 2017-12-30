#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct game_char_t game_char;

struct game_char_t{int hp, max_damage;};

int fight(game_char *hero, game_char *dragon);
void dragon_atack(game_char *hero, game_char *dragon, int head);
void hero_atack(game_char *hero, game_char *dragon, int head);
int hit(int random);

int main(int argc, char **argv)
{
	srand(time(0));

	game_char hero = {100, 30};
	game_char dragon[3];
	for(int i = 0; i < 3; i++)
	{
		dragon[i].hp = 75;
		dragon[i].max_damage = 10;
	}
	
	fight(&hero, dragon);
	
	return 0;
}

int fight(game_char *hero, game_char *dragon)
{
	int head = rand() % 3;
	int dead_heads = 0;
	printf("Hero vs Dragon head %d\n", head + 1);
	while(1)
	{
		hero_atack(hero, dragon, head);
		if(dragon[head].hp <= 0)
		{
			printf("Dragon head %d is dead!\n", head + 1);
			printf("Hero left with %d HP\n", hero -> hp);
			dead_heads++;
			if(dead_heads == 3)
			{
				printf("\nDRAGON IS DEAD!\n");
				return 1;
			}
			while(dragon[head].hp <= 0 )
				head = rand() % 3;
			printf("Hero vs Dragon head %d\n", head + 1);
		}
		dragon_atack(hero, dragon, head);
		if(hero -> hp <= 0)
		{
			printf("\nHero is dead\n");
			printf("Dragon left with HP: ");
			for(int i = 0; i < 3; i++)
				printf("%d ", dragon[i].hp);
			return 0;
		}
	}
}

int hit(int max_possible)
{
	if(rand() % 8 == 7 && max_possible == 30)
		return 50;
	int damage;
	do
	{	
		damage = rand() % (max_possible + 1);
	}while(damage == 0);
	return damage;
}

void hero_atack(game_char *hero, game_char *dragon, int head)
{
	int damage = hit(hero -> max_damage);	
	dragon[head].hp -= damage;
}

void dragon_atack(game_char *hero, game_char *dragon, int head)
{
	int damage = hit(dragon[head].max_damage);
	hero -> hp -= damage;
}
