#ifndef FUNCTIONS_H
#define FUCTIONS _H
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN
#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>


void setup(int szelesseg, int magassag, int x, int y, char array[], int hash[20][10]);
char drawIntro(int szelesseg, int magassag, int x, int y, char array[], int hash[20][10]);
int drawMap(int szelesseg, int magassag, int x, int y, char array[], int hash[20][10]);
int finalBoss(int szelesseg, int magassag, int x, int y, char array[], int hash[20][10], char hero);
void win();
bool printStats(int hp, int power, int coin);
//void input(dir);
//void logic(enum eDirection, int x, int y);
void GameOver();

#endif