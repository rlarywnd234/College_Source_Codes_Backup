/*
	==================================================
	Workshop #5 (Part-2):
	==================================================
	Name   :KYOJUNG KIM
	ID     :kkim107
	Email  :kkim107@myseneca.ca
	Section:IPC144ZAA
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>


struct Playerinformation
{
	int lives;
	char character;
	char player_history[4][71];
	int encounter;

};

struct Gameinfo
{
	int length;
	int move;
	char bomb_location[71];
	char treasure_location[71];
};

int p_lives(int a)
{
	while (a < 1 || a > 10)
	{
		printf("     Must be between 1 and 10!");
		printf("\nSet the number of lives: ");
		scanf(" %d", &a);
	}
	printf("Player configuration set-up is complete\n\n");
	return a;
}

int G_configuration(int a)
{
	while ((a < 10 || a>70) || (a % 5 != 0))
	{
		printf("     Must be a multiple of 5 and between 10-70!!!\n");
		printf("Set the path length (a multiple of 5 between 10-70): ");
		scanf(" %d", &a);
	}
	return a;
}

void move_and_state(struct Playerinformation p, struct Gameinfo g)
{
	printf("+---------------------------------------------------+\n");
	printf("  Lives:  %d  | Treasures:  %d  |  Moves Remaining: %2d\n", p.lives, p.encounter, g.move);
	printf("+---------------------------------------------------+\n");
}

int Next_moving(int a, struct Gameinfo g)
{
	printf("Next Move [1-%d]: ", g.length);
	scanf(" %d", &a);
	while (a < 1 || a > g.length)
	{
		printf("  Out of Range!!!\n");
		printf("Next Move [1-%d]: ", g.length);
		scanf(" %d", &a);
	}
	return a;

}
void State(struct Playerinformation p)
{
	printf("\n  %s\n", p.player_history[3]);
	printf("  %s\n", p.player_history[0]); // checking ----------- player_history location.//
	printf("  %s\n", p.player_history[1]);
	printf("  %s\n", p.player_history[2]);
}
void gameover(struct Playerinformation p, struct Gameinfo g)
{
	if (p.lives == 0)
	{
		printf("\nNo more LIVES remaining!\n");
	}
	else if (g.move == 0)
	{
		printf("\nNo more MOVE remaining!\n");
	}
}
int main(void)
{
	struct Playerinformation P_info;
	struct Gameinfo G_info;
	double max;
	char store_value;
	int i;
	P_info.encounter = 0;

	printf("================================\n         Treasure Hunt!         \n================================\n\n");
	printf("PLAYER Configuration\n--------------------\n");
	printf("Enter a single character to represent the player: ");
	scanf(" %c", &P_info.character);

	printf("Set the number of lives: ");
	scanf(" %d", &P_info.lives);
	P_info.lives = p_lives(P_info.lives);//no error //printf("%d   %c", info.lives, info.character); // checking vaildate data.

	printf("GAME Configuration\n------------------\n");           //length
	printf("Set the path length (a multiple of 5 between 10-70): ");
	scanf("%d", &G_info.length);
	G_info.length = G_configuration(G_info.length);





	max = (double)G_info.length * 0.75; // 75% 

	printf("Set the limit for number of moves allowed: ");
	scanf(" %d", &G_info.move);
	while (G_info.move < P_info.lives || G_info.move > max)
	{
		printf("    Value must be between %d and %.0lf\n", P_info.lives, max);
		printf("Set the limit for number of moves allowed: ");
		scanf(" %d", &G_info.move);
	}

	printf("\nBOMB Placement\n--------------\nEnter the bomb positions in sets of 5 where a value\nof 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", G_info.length);
	for (i = 0; i < G_info.length;)
	{
		printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
		scanf("%s %s %s %s %s", &G_info.bomb_location[i], &G_info.bomb_location[i + 1], &G_info.bomb_location[i + 2], &G_info.bomb_location[i + 3], &G_info.bomb_location[i + 4]);

		i = i + 5;
	}
	printf("BOMB placement set\n\n");
	// BOMB



	printf("TREASURE Placement\n------------------\nEnter the treasure placements in sets of 5 where a value\nof 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", G_info.length);
	for (i = 0; i < G_info.length;)
	{
		printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
		scanf("%s %s %s %s %s", &G_info.treasure_location[i], &G_info.treasure_location[i + 1], &G_info.treasure_location[i + 2], &G_info.treasure_location[i + 3], &G_info.treasure_location[i + 4]);
		i = i + 5;
	}
	printf("TREASURE placement set\n\n");
	// TREASURE

	for (i = 0; i < G_info.length;) // ----------- and ||||||||||1||||||||||2 logic
	{
		P_info.player_history[0][i] = '-';
		P_info.player_history[1][i] = '|';
		P_info.player_history[3][i] = ' ';

		if ((i + 1) >= 10 && (i + 1) % 10 == 0)
		{
			store_value = ((i + 1) / 10) + '0';
			P_info.player_history[1][i] = store_value;

		}
		++i;
	}
	P_info.player_history[0][G_info.length] = 0;
	P_info.player_history[1][G_info.length] = 0;
	P_info.player_history[3][G_info.length] = 0;

	for (i = 0; i < G_info.length;)// 1234567890 logic
	{
		if ((i + 1) > 10)
		{
			P_info.player_history[2][i] = ((i + 1) % 10) + '0';
			i++;
			continue;
		}

		if ((i + 1) % 10 == 0)
		{
			P_info.player_history[2][i] = '0';
			i++;
			continue;
		}
		if ((i + 1) < 10)
		{
			P_info.player_history[2][i] = (i + 1) + '0';
			i++;
			continue;
		}
	}
	P_info.player_history[2][G_info.length] = 0;

	printf("GAME configuration set-up is complete...\n\n------------------------------------\nTREASURE HUNT Configuration Settings\n------------------------------------\n");
	printf("Player:\n   Symbol     : %c\n   Lives      : %d\n   Treasure   : [ready for gameplay]\n   History    : [ready for gameplay]\n", P_info.character, P_info.lives);

	printf("\nGame:\n   Path Length: %d\n   Bombs      : %s\n   Treasure   : %s\n\n", G_info.length, G_info.bomb_location, G_info.treasure_location);
	printf("====================================\n~ Get ready to play TREASURE HUNT! ~\n====================================\n\n");



	/////////PART 2 START AT HERE/////////

	printf("  %s\n", P_info.player_history[0]); // checking ----------- player_history location.//
	printf("  %s\n", P_info.player_history[1]);
	printf("  %s\n", P_info.player_history[2]);
	i = 0;

	while (P_info.lives != 0 && G_info.move != 0)
	{
		move_and_state(P_info, G_info);
		i = Next_moving(i, G_info);
			 if (P_info.player_history[0][(i - 1)] == '.' || P_info.player_history[0][(i - 1)] == '!' || P_info.player_history[0][(i - 1)] == '&' || P_info.player_history[0][(i - 1)] == '$')//you have been here
		{// Playe history recorder = . ! & $
		printf("\n===============> Dope! You've been here before!\n");
		gameover(P_info, G_info);
		P_info.player_history[3][(i - 1)] = P_info.character;
		State(P_info);
		P_info.player_history[3][(i - 1)] = ' ';
		G_info.move--;
		continue;
		}

		else if (G_info.bomb_location[(i - 1)] == '0' && G_info.treasure_location[(i - 1)] == '0')//nothing here
		{
			printf("\n===============> [.] ...Nothing found here... [.]\n");
			gameover(P_info, G_info);
			P_info.player_history[0][(i - 1)] = '.';
			P_info.player_history[3][(i - 1)] = P_info.character;
			State(P_info);
			P_info.player_history[3][(i - 1)] = ' ';
			G_info.move--;
			continue;
		}
	
		else if (G_info.bomb_location[(i - 1)] == '1' && G_info.treasure_location[(i - 1)] == '0') //bomb!!!!!!!!
		{// bomb = 1 and treasure = 0
			printf("\n===============> [!] !!! BOOOOOM !!! [!]\n");
			P_info.lives = P_info.lives - 1;
			gameover(P_info, G_info);
			P_info.player_history[0][(i - 1)] = '!';
			P_info.player_history[3][(i - 1)] = P_info.character;
			State(P_info);
			P_info.player_history[3][(i - 1)] = ' ';
			G_info.move--;
			continue;
		}

		else if (G_info.bomb_location[(i - 1)] == '1' && G_info.treasure_location[(i - 1)] == '1')// bomb and treasure
		{// bomb = 1 treasure = 1
			printf("\n===============> [&] !!! BOOOOOM !!! [&]\n===============> [&] $$$ Life Insurance Payout!!! [&]\n");
			P_info.lives = P_info.lives - 1;
			gameover(P_info, G_info);
			P_info.player_history[0][(i - 1)] = '&';
			P_info.player_history[3][(i - 1)] = P_info.character;
			P_info.encounter = P_info.encounter + 1;
			State(P_info);
			P_info.player_history[3][(i - 1)] = ' ';
			G_info.move--;
			continue;
		}

		else if (G_info.treasure_location[(i - 1)] == '1' && G_info.bomb_location[(i - 1)] == '0')
		{// treasure = 1 bomb = 0
			printf("\n===============> [$] $$$ Found Treasure! $$$ [$]\n");
			gameover(P_info, G_info);
			P_info.player_history[0][(i - 1)] = '$';
			P_info.player_history[3][(i - 1)] = P_info.character;
			P_info.encounter = P_info.encounter + 1;
			State(P_info);
			P_info.player_history[3][(i - 1)] = ' ';
			G_info.move--;
			continue;
		}
	}
	move_and_state(P_info, G_info);
	printf("\n##################\n#   Game over!   #\n##################\n\n");
	printf("You should play again and try to beat your score!!\n");

	return 0;
}
