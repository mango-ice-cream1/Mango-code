#include<stdio.h>
//#define _CRT_SECURE_NO_WARNINGS
#define ROW 3
#define COL 3

void menu();
void Initboard(char board[][COL],int row,int col);
void Printboard(char board[][COL], int row, int col);
void Playermove(char board[][COL],int row,int col);
void Computermove(char board[][COL]);
char Iswin(char board[][COL],int row,int col);