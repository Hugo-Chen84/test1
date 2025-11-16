#pragma execution_character_set("gbk")
#define _CRT_SECURE_NO_WARNINGS

#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#define ROW 9
#define COL 9

#define ROWS 11
#define COLS 11

#define EASY_COUNT 10

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
void DisplayBoard(char board[ROWS][COLS], int row, int col);
void Setmine(char board[ROWS][COLS], int row, int col);
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
int sweepmine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);
