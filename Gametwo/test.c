#include"game.h"

void game()
{
	char mine[ROWS][COLS] = { 0 };//����
	char exposure[ROWS][COLS] = { 0 };//�Ų��������
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
	srand((unsigned int)time(NULL));//����ʱ��������������
	do
	{		
		menu();
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			printf("ɨ��!\n");
			game();
			break;
		case 0:
			printf("�˳�!\n");
			exit(0);
			break;
		default:
			printf("��������,��������!\n");
			break;
		}

	} while (input);

	return 0;
}