#include"game.h"

void game()
{
	char mine[ROWS][COLS] = { 0 };//mines
	char exposure[ROWS][COLS] = { 0 };//exposure mines
	Initboard(mine,ROWS, COLS, '0');
	Initboard(exposure, ROWS, COLS, '*');

	printboard(exposure, ROW, COL);

	SetMine(mine,ROW,COL);

	FindMine(mine,exposure,ROWS,COLS);
	
	//printboard(exposure, ROW, COL);
}

void menu()
{
	printf("*******   Game  *********\n");
	printf("******* 1.play  *********\n");
	printf("******* 0.exit  *********\n");
	printf("*******   Game  *********\n");
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//accoring to time to create random nums
	do
	{		
		menu();
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			printf("FInd MIne!\n");
			game();
			break;
		case 0:
			printf("exit!\n");
			exit(0);
			break;
		default:
			printf("Wrong!Please input again!\n");
			break;
		}

	} while (input);

	return 0;
}
