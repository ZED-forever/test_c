#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//常量
#define ROW 3
#define COL 3
//函数
void InitBoard(char board[ROW][COL],int row,int col);
void PrintBoard(char board[ROW][COL],int row,int col);
void PlayerMove(char board[ROW][COL],int row,int col); 
void ComputerMove(char board[ROW][COL],int row,int col);
char IsWin(char board[ROW][COL],int row,int col);