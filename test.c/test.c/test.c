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
	//����������λ���飬��������

	char RealMine[ROWS][COLS] = { 0 };
	char ShowMine[ROWS][COLS] = { 0 };
	//��ʼ��
	InitBoard(ROWS, COLS, RealMine, '0');//����Ҳ��Ҫ����ȥһ���ַ�'0'�������ڲ����ܶ��庯��
	InitBoard(ROWS, COLS, ShowMine, '*');//Ϊʲô����ֻ��ʼ��һ��
	//Display(ROW, COL, ShowMine);//dayin
	//Display(ROW, COL, RealMine);
	//��������
	SetMine(ROW, COL, RealMine);
	Display(ROW, COL, ShowMine);
	Display(ROW, COL, RealMine);
	//����
	FindMine(ROW, COL, RealMine, ShowMine);
	//Display(ROW, COL, ShowMine);
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	printf("������ѡ��\n");
	menu();
	do{
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("��Ϸ�˳�\n");
			break;
		default:
			printf("ѡ���������������\n");
		}
	} while (1);
}
int main()
{
	test();
	system("pause");
	return 0;
}
//1 ������Ҫ���
//��ʼ����������ʼ���������󣬼�������ά���飩
//����ɨ����Ϸ���й��̺ͽ����ÿ�����
