#include"game.h"

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

void printboard(char board[ROWS][COLS], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		printf("%d ", i);
	}

	printf("\n");


	for (int i = 1; i < row; i++)
	{
		printf("%d ", i);
		for (int j = 1; j < col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
//�жϸ������׵���Ŀ
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
//�Ų���
void FindMine(char mine[ROWS][COLS], char exposure[ROWS][COLS], int row, int col)
{
	int m, n;
	
	while (1)
	{
		printf("�����Ų�����>");
		scanf_s("%d%d", &m, &n);

		if (m >= 1 && m <= row && n >= 1 && n <= col)
		{
			if (mine[m][n] == '1')
			{
				printf("��,�㱻ը����\n");
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
			printf("��������ȷ������!\n");
		}
	}
	
}

//������
void SetMine(char mine[ROWS][COLS], int row, int col)
{
	int count = 10;

	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % row + 1;		

		if (mine[x][y]=='0')//���û����
		{
			mine[x][y] = '1';//����
			count--;
		}
	}
}