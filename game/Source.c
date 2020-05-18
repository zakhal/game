#include "Functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h> 
#include <windows.h>

bool gameOver;
const int szelesseg = 20;
const int magassag = 10;
int x, y;
char hero;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
enum eDirection dir;
int hp = 3;
int power = 3;
int coin = 3;
int action = 0;
int levelClear = 0;

void input()
{
	switch (_getch()) {
	case 'a':
		dir = LEFT;
		break;
	case 'd':
		dir = RIGHT;
		break;
	case 'w':
		dir = UP;
		break;
	case 's':
		dir = DOWN;
		break;
	default:
		break;
	}

}

void logic(int hash[20][10])
{
	switch (dir) {
	case LEFT:
		if (x != 0) {
			if (hash[x - 1][y] != 0) {
				hash[x][y] = 50;
				x--;
			}
		}
		break;
	case RIGHT:
		if (x != szelesseg - 1) {
			if (hash[x + 1][y] != 0) {
				hash[x][y] = 50;
				x++;
			}
		}
		break;
	case UP:
		if (y != 0) {
			if (hash[x][y - 1] != 0) {
				hash[x][y] = 50;
				y--;
			}
		}
		break;
	case DOWN:
		if (y != magassag - 1) {
			if (hash[x][y + 1] != 0) {
				hash[x][y] = 50;
				y++;
			}
		}
		break;
	default:
		break;
	}
}

int main() {
	gameOver = false;
	x = 0;
	y = 0;

	char array[] = { '@', 'p', 'c', 'r', 'b', 'z', 'o', 'r', 'k', 'n' };
	char loot[] = { '+', '-', '^', '/', '.', ',', '*' };
	time_t t;
	srand((unsigned)time(&t));
	int hash[10][20];
	

	for (int i = 0; i < magassag; ++i) {
		for (int j = 0; j < szelesseg; ++j) {
			hash[i][j] = 1;
		}
	}

	setup(szelesseg, magassag, x, y, array, hash);
	while (drawIntro(szelesseg, magassag, x, y, array, hash, hero) == 'x') {
		dir = STOP;
		drawIntro(szelesseg, magassag, x, y, array, hash, hero);
		input();
		logic(hash);
	}
	hero = drawIntro(szelesseg, magassag, x, y, array, hash, hero);

	for (int i = 0; i < magassag; ++i) {
		for (int j = 0; j < szelesseg; ++j) {
			hash[i][j] = rand() % 40;
		}
	}
	for (int i = 0; i < szelesseg + magassag; ++i) {
		hash[rand() % magassag][rand() % szelesseg] = 0;
	}

	hash[0][0] = 50;
	hash[0][1] = 50;
	hash[9][18] = 50;
	hash[9][19] = 50;
	x = 0;
	y = 0;
	while (!gameOver) {
		dir = STOP;
		drawMap(szelesseg, magassag, x, y, array, hash, hero, loot);
		action = drawMap(szelesseg, magassag, x, y, array, hash, hero, loot);
		gameOver = printStats(hp, power, coin, action);
		input();
		logic(hash);
		switch (action) {
		case 1:
			hp++;
			break;
		case 2:
			hp--;
			break;
		case 3:
			power++;
			break;
		case 4:
			power--;
			break;
		case 5:
			coin++;
			break;
		case 6:
			coin--;
			break;
		case 7:
			hp = hp + rand() % 1 - 1;
			power = power + rand() % 1 - 1;
			coin = coin + rand() % 1 - 1;
			break;
		default:
			break;
		}
		if (y == 9 && x == 19) {
			levelClear++;
			for (int i = 0; i < magassag; ++i) {
			for (int j = 0; j < szelesseg; ++j) {
					hash[i][j] = rand() % 40;
				}
			}
			for (int i = 0; i < szelesseg + magassag; ++i) {
				hash[rand() % magassag][rand() % szelesseg] = 0;
			}

			hash[0][0] = 50;
			hash[0][1] = 50;
			hash[9][18] = 50;
			hash[9][19] = 50;
			x = 0;
			y = 0;
			drawMap(szelesseg, magassag, x, y, array, hash, hero, loot);
			if (levelClear == 3) {
				break;
			}
	}
	}
	for (int i = 0; i < magassag; ++i) {
		for (int j = 0; j < szelesseg; ++j) {
			hash[i][j] = 50;
		}
	}
	hash[magassag - 2][szelesseg - 2] = 30;
	x = 0;
	y = 0;
	int fine = 5;
	if (levelClear == 3) {
		while (fine == 5) {
			dir = STOP;
			fine = finalBoss(szelesseg, magassag, x, y, array, hash, hero);
			input();
			logic(hash);
		}
	}
	switch (fine) {
	case 1:
		if (power >= 10) {
			printf("parbajoztok, gyoztel");
			_getch();
			win();
		}
		else {
			printf("nem voltal eleg eros, osszeroppint");
			_getch();
		}
		break;
	case 2:
		if (hp >= 10) {
			printf("szerelembe estek, osszehazasodtok es ateled");
			_getch();
			win();
		}
		else {
			printf("nincs eleg szived, kikosaraz");
			_getch();
		}
		break;
	case 3:
		if (coin >= 10) {
			printf("oda adod az osszes penzed, el enged");
			_getch();
			win();
		}
		else {
			printf("nincs eleg penzed, leszur");
			_getch();
		}
		break;
	case 4:
		printf("ez nem a szamuraj eletmod, kivegez");
		_getch();
		break;
	}

	GameOver(hp, power, coin);
	//_getch();
	return 0;
}