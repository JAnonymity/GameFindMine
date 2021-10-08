#include"game.h"

void game()
{
	char mine[ROWS][COLS] = { 0 };//雷区
	char exposure[ROWS][COLS] = { 0 };//排查出的雷区
	Initboard(mine,ROWS, COLS, '0');
	Initboard(exposure, ROWS, COLS, '*');

	printboard(exposure, ROWS, COLS);

	SetMine(mine,ROW,COL);

	FindMine(mine,exposure,ROWS,COLS);
	
	//printboard(exposure, ROWS, COLS);
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
	srand((unsigned int)time(NULL));//根据时间进行随机生成数
	do
	{		
		menu();
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			printf("扫雷!\n");
			game();
			break;
		case 0:
			printf("退出!\n");
			exit(0);
			break;
		default:
			printf("输入有误,重新输入!\n");
			break;
		}

	} while (input);

	return 0;
}