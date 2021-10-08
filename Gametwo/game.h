#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MINECOUNT 10
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2


void Initboard(char board[ROWS][COLS], int row, int col, char ch);

void printboard(char board[ROWS][COLS], int row, int col);

void FindMine(char mine[ROWS][COLS], char exposure[ROWS][COLS], int row, int col);

void SetMine(char mine[ROWS][COLS],int row, int col);
