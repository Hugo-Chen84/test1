#include "game.h"


void menu()
{
	printf("*****************************\n");
	printf("********   1. play   ********\n");
	printf("********   0. exit   ********\n");
	printf("*****************************\n");

}
void game()
{
	char mine[ROWS][COLS] = { ' ' };
	char show[ROWS][COLS] = { '*' };
	InitBoard(mine, ROWS, COLS, ' ');
	InitBoard(show, ROWS, COLS, '*');

	Setmine(mine, ROW, COL);
	DisplayBoard(show,ROW,COL);
	FindMine(mine, show,ROW,COL);
}


void setConsoleEncoding() {
	system("chcp 936 > nul");
	SetConsoleOutputCP(936);
}


int main(void)
{
	setConsoleEncoding();
	int input = 0;

	do
	{
		srand((unsigned)time(NULL));

		menu();
		printf("输入1开始游戏，输入0退出游戏，请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("游戏开始，共有10个雷。\n*为未排查的位置，数字为已排查的位置并显示其周围的雷的数量\n");
			game();
			break;
		case 0:
			printf("5秒后退出游戏\n");
			Sleep(5000);
			break;
		default:
			printf("选择错误\n");
			break;

		}
	} while (input);

	return 0;
}