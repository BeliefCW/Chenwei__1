#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1  
#include <stdio.h>
#include "game.h"



void InitBoard(int rows, int  cols, char board[ROWS][COLS], char set)//��ʼ���������󣬵�һ���������Լ��������ģ��á�0����ʾ��'1'��ʾ��
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
void SetMine(int row, int col, char board[ROWS][COLS])//������
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

void FindMine(int row, int col, char board[ROWS][COLS], char board1[ROWS][COLS])//����
{
	int win = 0;
	int count = 0;
	int x = 0;
	int y = 0;
	//printf("����������:\n");
	//scanf("%d %d", &x, &y);
	while (win <= ROW*COL - easy_count)
	{
		printf("����������:\n");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row&&y >= 1 && y <= col)
		{
			if (board[x][y] == '1')
			{
				board1[x][y] = '1';
				printf("���ź�����������\n")\;
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
			printf("�����������������");
		}
	}
}


