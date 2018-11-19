#ifndef _GAME_H_
#define _GAME_H_

#include "game.h"
#include <stdio.h>
#include "game.h"


#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define easy_count 10



void InitBoard(int rows, int cols, char RealMine[ROWS][COLS], char set);//此块定义的要与game.c中的函数一样
void Display(int row, int  col, char ShowMine[ROWS][COLS]);
void SetMine(int row, int col, char board[ROWS][COLS]);
void FindMine(int row, int col, char board[ROWS][COLS], char board1[ROWS][COLS]);
#endif