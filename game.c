//#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include "game.h"

void menu()
{
	printf("********************\n");
	printf("***** 1. play ******\n");
	printf("***** 0. exit ******\n");
	printf("********************\n");
}

//棋盘初始化
void Initboard(char board[][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	/*for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
			printf("%c ", board [i][j]);
	}*/
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			board [i][j] = ' ';
	}
}

//打印棋盘
void Printboard(char board[][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if(i<row-1)
		for (j = 0; j < col; j++)
		{
			printf("___");
			if(j<col-1)
			printf("|");
		}
		printf("\n");
	}
}

//玩家走
void Playermove(char board[][COL],int row,int col)
{
	printf("玩家走：\n");
	while(1)
	{
		int x = 0;
		int y = 0;
		printf("请输入下子位置:》\n");
		scanf("%d %d", &x, &y);
		if ((x > 0 && x <= row) && (y > 0 && y <= col))
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}	
			else
				printf("该位置被占用\n");
		}
		else
			printf("输入错误，请重新输入！\n");
	}
}

//电脑走
void Computermove(char board[][COL])
{
	printf("电脑走：\n");
	while (1)
	{
		int x = rand() % 3;
		int y = rand() % 3;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

//胜负判断四种状态
// 玩家赢 *
// 电脑赢 #
// 平局   Q
// 游戏继续 C

//判断棋盘是否被填满
int IsFull(char board[][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;//返回0表示没满
			}
		}
	}
	return 1;//返回1表示满了
}
char Iswin(char board[][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//行判断（行扫描）
	for (i = 0; i < row; i++)
	{
		if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}

	//列判断（列扫描）
	for (j = 0; j < col; j++)
	{
		if ((board[0][j] == board[1][j]) && (board[1][j] == board[2][j]) && board[0][j] != ' ')
		{
			return board[0][j];
		}
	}

	//斜45°十字判断
	if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && board[0][0] != ' ')
	{
		return board[0][0];
	}
	if ((board[2][0] == board[1][1]) && (board[1][1] == board[0][2]) && board[2][0] != ' ')
	{
		return board[2][0];
	}

	//平局判断
	if (1 == IsFull(board, ROW, COL))
	{
		return 'Q';
	}
	//游戏继续
	return 'C';
}
