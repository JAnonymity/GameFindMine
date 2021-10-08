#include"game.h"

//Init playing board
void Initboard(char board[ROWS][COLS], int row, int col, char ch)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = ch;
		}
	}
}

//Print playing board
void printboard(char board[ROWS][COLS], int row, int col)
{
	for (int i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}

	printf("\n");


	for (int i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (int j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
//judge Mines' Num around
int judgeMineNum(char mine[ROWS][COLS], int row, int col)
{
	int count = 0;
	if (mine[row-1][col-1]=='1'|| mine[row-1][col] == '1' || mine[row-1][col+1] == '1'
		|| mine[row][col - 1] == '1' || mine[row][col+1] == '1'
		|| mine[row+1][col - 1] == '1' || mine[row+1][col] == '1' || mine[row+1][col + 1] == '1')
	{
		count++;
	}

	return count;
}
//Find mine
void FindMine(char mine[ROWS][COLS], char exposure[ROWS][COLS], int row, int col)
{
	int m, n;
	int win=0;
	while (win<row*col-MINECOUNT)
	{
		printf("[");
		scanf_s("%d,%d", &m, &n);
		printf("]");
		if (m >= 1 && m <= row && n >= 1 && n <= col)
		{
			if (mine[m][n] == '1')
			{
				printf("You are unlucky\n");
				printboard(mine,row,col);
				break;
			}
			else
			{
				int count = judgeMineNum(mine, m, n);
				exposure[m][n] = count+'0';		
				printboard(exposure, row, col);
			}
		}
		else
		{
			printf("Print right pos please!\n");
		}
	}
	
	if(win==row*col-MINECOUNT)
	{
		printf("Congratulations,You win!\n");
	}
	
}

//Set mines in your playing board
void SetMine(char mine[ROWS][COLS], int row, int col)
{
	int count = MINECOUNT;

	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % row + 1;		

		if (mine[x][y]=='0')//'0'means there isn't a mine
		{
			mine[x][y] = '1';//'1'means there is a mine
			count--;
		}
	}
}
