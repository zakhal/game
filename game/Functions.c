#include "Functions.h"

void setup(int szelesseg, int magassag, int x, int y, char array[], int hash[20][10])
{

		system("cls");
		printf(" valassz egy karaktert aki szeretnel lenni!\n");
		printf(" el kell erj a palyak jobb also sarkaba, hogy tovabbjuss a dungeonban\n");
		printf(" a palyak tel vannak kulonbozo targyakkal amelyek esetekben erositenek,\n");
		printf(" gazdagitanak, eleterot adnak vagy eppen ezeknek az ellenkezojet teszik\n");
		printf(" a lenyeg, hogy megjegyezd melyik targy mit tesz, es ugy vegigmenj a palyakon,\n");
		printf(" hogy az utolso bossnal eleg eros vagy ugyes legyel, hogy ot legyozd\n");
		printf(" egy segitseget kapsz a * karakter egy veletlenszeru hatassal lesz rad\n");
		printf(" a karaktert iranyitsd a kovetkezo gombokkal: W,A,S,D");
		_getch();
	
}

char drawIntro(int szelesseg, int magassag, int x, int y, char array[], int hash[20][10], char hero)
{
	hero = array[rand() % 10];
	system("cls");
	for (int i = 0; i < szelesseg + 2; ++i) {
		printf("#");
	}
	printf("\n");
	int k = 0;
	for (int i = 0; i < magassag; ++i) {
		for (int j = 0; j < szelesseg; ++j) {
				if (j == 0) {
					printf("#");
				}
				if (i == y && j == x) {
					printf("%c", hero);
				}
				else if (hash[j][i] == 0) {
					printf("#");
				}
				else if (i == magassag - 2 && j % 2 == 0) {
					printf("%c", array[k++]);
				}
				else {
					printf(" ");
				}

				if (j == szelesseg - 1) {
					printf("#");
					printf("\n");
				}
				if (y == 8 && x % 2 == 0) {
					return array[x / 2];
					break;
				}
		}
	}
	for (int i = 0; i < szelesseg + 2; ++i) {
		printf("#");
	}
	//printf("\n");
	//printf("y= ");
	//printf("%d ", y);
	//printf("x= ");
	//printf("%d", x);
	//printf("\n");
	return 'x';

}

int drawMap(int szelesseg, int magassag, int x, int y, char array[], int hash[20][10], char hero, char loot[])
{
	system("cls");
	for (int i = 0; i < szelesseg + 2; ++i) {
		printf("#");
	}
	printf("\n");
	for (int i = 0; i < magassag; ++i) {
		for (int j = 0; j < szelesseg; ++j) {
			if (j == 0) {
				printf("#");
			}
			if (i == y && j == x) {
				//hash[y][x] = 50;
				printf("%c", hero);
			}
			else if (hash[j][i] == 0) {
				printf("#");
			}
			else if (hash[j][i] == 1) {
				printf("%c", loot[0]);
			}
			else if (hash[j][i] == 2) {
				printf("%c", loot[1]);
			}
			else if (hash[j][i] == 3) {
				printf("%c", loot[2]);
			}
			else if (hash[j][i] == 4) {
				printf("%c", loot[3]);
			}
			else if (hash[j][i] == 5) {
				printf("%c", loot[4]);
			}
			else if (hash[j][i] == 6) {
				printf("%c", loot[5]);
			}
			else if (hash[j][i] == 7) {
				printf("%c", loot[6]);
			}
			else {
				printf(" ");
			}
			if (j == szelesseg - 1) {
				printf("#");
			}
		}
		printf("\n");
	}
	for (int i = 0; i < szelesseg + 2; ++i) {
		printf("#");
	}
	//printf("\n");
	//printf("y= ");
	//printf("%d ", y);
	//printf("x= ");
	//printf("%d", x);
	printf("\n");
	
	if (y == 9 && x == 1) {
		return 100;
	}

	return hash[x][y];
}

void GameOver(int hp, int power, int coin) {
	system("cls");
	if (hp == 0) {
		printf(" elfogyott az eleterod, meghaltal :(\n");
	}
	else if (power == 0) {
		printf(" legyengultel, meghaltal :(\n");
	}
	else if (coin == 0) {
		printf(" csodbe jutottal, meghaltal :(\n");
	}
	printf(" GAME OVER");
}

bool printStats(int hp, int power, int coin, int action) {
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
	default:
		break;
	}
	if (hp == 0 || power == 0 || coin == 0) {
		return true;
	}
	else {
		printf("HP:%d ", hp);
		printf("POWER:%d ", power);
		printf("COIN:%d ", coin);
		return false;
	}
}

int finalBoss(int szelesseg, int magassag, int x, int y, char array[], int hash[20][10], char hero)
	{
		system("cls");
		for (int i = 0; i < szelesseg + 2; ++i) {
			printf("#");
		}
		printf("\n");

		for (int i = 0; i < magassag; ++i) {
			for (int j = 0; j < szelesseg; ++j) {
				if (j == 0) {
					printf("#");
				}
				if (i == y && j == x) {
					printf("%c", hero);
				}
				else if (hash[j][i] == 30) {
					printf("%c", array[rand() % 10]);
				}
				else {
					printf(" ");
				}
				if (j == szelesseg - 1) {
					printf("#");
				}
			}
			printf("\n");
		}
		for (int i = 0; i < szelesseg + 2; ++i) {
			printf("#");
		}
		printf("\n");
		printf("o itt a final bosz :)\n");
		//printf("\n");
		//printf("y= ");
		//printf("%d ", y);
		//printf("x= ");
		//printf("%d", x);
		//printf("\n");
		if ((y == 8) && (x == 17)) {
			printf(" valaszd ki a strategiat amivel megprobalod legyozni\n");
			printf(" w : lefizeted\n");
			printf(" a : tisztessegesen megkuzdesz vele\n");
			printf(" s : kegyelemert esedezel\n");
			printf(" d : elcsabitod\n");
			switch (_getch()) {
			case 'a':
				return 1;
				break;
			case 'd':
				return 2;
				break;
			case 'w':
				return 3;
				break;
			case 's':
				return 4;
				break;
			default:
				return 5;
				break;
			}
		}
		return 5;
	}

void win() {
	system("cls");
	printf(" ugyess vagy nyertel");
	_getch();
	exit(0);
}