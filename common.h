#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <mmsystem.h>

#pragma warning(disable :4996)

#define MAX_SIZE_X 70
#define MAX_SIZE_Y 25
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

int score;
int board[MAX_SIZE_X][MAX_SIZE_Y];
int flagID[MAX_SIZE_X][MAX_SIZE_Y];
int difficulty;
int remainingstone;
int life;
int remainingTime;
static int pauseEnemies = 0;
HANDLE consoleMutex;


void initializeObjects();
void printBoard();
void gotoxy(int x, int y);
void flagmeet(int id);
void enemymeet();
void playGame();
void ending(int success);
void showStory();
void showStartScreen();
void selectDifficulty();
void showTutorial();
void printlifes();
void games();
DWORD WINAPI moveEnemies(LPVOID lpParam);
DWORD WINAPI handlePlayer(LPVOID lpParam);
void printTypingEffect(const char* text, int delay, int* stopFlag);