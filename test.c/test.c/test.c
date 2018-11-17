#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include "game.h"
#include<string.h>
#include <time.h>

void menu()
{
	printf("**********************\n");
	printf("*****1.piay 0.exit****\n");
	printf("**********************\n");
}

void game()
{
	//创建两个二位数组，用作雷盘

	char RealMine[ROWS][COLS] = { 0 };
	char ShowMine[ROWS][COLS] = { 0 };
	//初始化
	InitBoard(ROWS, COLS, RealMine, '0');//这里也需要传过去一个字符'0'，函数内部不能定义函数
	InitBoard(ROWS, COLS, ShowMine, '*');//为什么这里只初始化一次
	//Display(ROW, COL, ShowMine);//dayin
	//Display(ROW, COL, RealMine);
	//布置手雷
	SetMine(ROW, COL, RealMine);
	Display(ROW, COL, ShowMine);
	Display(ROW, COL, RealMine);
	//排雷
	FindMine(ROW, COL, RealMine, ShowMine);
	//Display(ROW, COL, ShowMine);
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	printf("请输入选择\n");
	menu();
	do{
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏退出\n");
			break;
		default:
			printf("选择错误，请重新输入\n");
		}
	} while (1);
}
int main()
{
	test();
	system("pause");
	return 0;
}
//1 函数主要框架
//初始化函数（初始化两个雷阵，及两个二维数组）
//分析扫雷游戏运行过程和结果及每种情况
