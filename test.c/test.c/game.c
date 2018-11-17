#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1  
#include <stdio.h>
#include "game.h"



void InitBoard(int rows, int  cols, char board[ROWS][COLS], char set)//初始化两个雷阵，第一个雷阵是自己所看到的，用‘0’表示，'1'表示雷
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
	//memset(&RealMine, '0', rows*cols*sizeof(RealMine[0][0]));
}
void Display(int row, int  col, char board[ROWS][COLS])
{
	int i = 0;
	int j = 0;
	for (j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
void SetMine(int row, int col, char board[ROWS][COLS])//创建雷
{
	int x = 0;
	int y = 0;
	int count = easy_count;
	while (count)
	{
		x = rand() % 9 + 1;
		y = rand() % 9 + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

void FindMine(int row, int col, char board[ROWS][COLS], char board1[ROWS][COLS])//排雷
{
	int win = 0;
	int count = 0;
	int x = 0;
	int y = 0;
	//printf("请输入坐标:\n");
	//scanf("%d %d", &x, &y);
	while (win <= ROW*COL - easy_count)
	{
		printf("请输入坐标:\n");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row&&y >= 1 && y <= col)
		{
			if (board[x][y] == '1')
			{
				board1[x][y] = '1';
				printf("很遗憾，您踩雷了\n")\;
				Display(ROW, COL, board);
				break;
			}
			else
			{
				count = board[x][y - 1] +
					board[x - 1][y - 1] +
					board[x - 1][y] +
					board[x - 1][y + 1] +
					board[x][y + 1] +
					board[x + 1][y + 1] +
					board[x + 1][y] +
					board[x + 1][y - 1] - 8 * '0';
				board1[x][y] = count + '0';
				Display(ROW, COL, board1);
				win++;
			}
		}
		else
		{
			printf("输入错误，请重新输入");
		}
	}
}


