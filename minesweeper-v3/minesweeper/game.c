#include "game.h"


void InitBoard(char board[ROWS][COLS], int rows, int cols, char set) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col) {
	printf("-----扫雷游戏------\n");
	for (int j = 0; j <= col; j++) {
		printf("%d ", j);
	}
	printf("\n");

	for (int i = 1; i <= row; i++) {
		printf("%d ", i);
		for(int j = 1; j <= col; j++) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("-----扫雷游戏------\n");

}

void Setmine(char board[ROWS][COLS], int row, int col) {
	int count = EASY_COUNT;
	while (count) {
		int x = rand() % row + 1;
		int y = rand() % col + 1;

		if (board[x][y] == ' ') {
			board[x][y] = '1';
			count--;
		}
	}
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) {
	int x, y;
	int win = 0;
	while (win<row*col-EASY_COUNT) {
		printf("请以“行 列”的格式（如1 1）输入要排查的坐标：>");
		if (scanf("%d %d", &x, &y) != 2) {
			int ch;
			while ((ch = getchar()) != '\n' && ch != EOF) {}
			printf("输入格式错误，请重新输入\n");
			continue;
		}
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (mine[x][y] == '1') {
				printf("Bomb!!!! Game over.\n");
				Sleep(2000);
				printf("游戏结束，下图中‘1’为本局游戏中雷的位置\n");
				DisplayBoard(mine, ROW, COL);
				Sleep(2000);

				break;
			}
			else if (show[x][y] != '*') {
				printf("此位置已经排查过了\n");
			}
			else {
				int pluswin = 0;
				pluswin = sweepmine(mine,show,x,y);
				win += pluswin;
				DisplayBoard(show, ROW, COL);

			}
		}
		else {
			printf("输入的坐标非法，请重新输入\n");
		}
	}

	if (win == row * col - EASY_COUNT) {
		printf("恭喜你，排雷成功\n");
		Sleep(3000);
		printf("游戏结束，下图中‘1’为本局游戏中雷的位置\n");
		DisplayBoard(mine, ROW, COL);
		Sleep(2000);
	}

}

int sweepmine(char mine[ROWS][COLS], char show[ROWS][COLS],int x,int y) {
	int sum = 0;
	
	if (x < 1 || x > ROW || y < 1 || y > COL) 
		return 0;
	if (show[x][y] != '*')
		return 0;

	for (int i = x - 1; i <= x + 1; i++) {
		for (int j = y - 1; j <= y + 1; j++) {
			if (mine[i][j] == '1')
				sum++;
		}
	}
	int revealed = 0;

	if (sum!=0) {
		show[x][y] = sum + '0';
		revealed = 1;
	}
	else{
		show[x][y] = ' ';
		revealed = 1;
		for (int i = x - 1; i <= x + 1; i++) {
			for (int j = y - 1; j <= y + 1; j++) {
				if (i < 1 || i > ROW || j < 1 || j > COL)
					continue;
				if (show[i][j] == '*') {
					revealed += sweepmine(mine, show, i, j);
				}
			}
		}
	}
	return revealed;
}
