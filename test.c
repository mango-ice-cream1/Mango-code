#include"game.h"
#include<stdlib.h>
#include<time.h>

void game()
{
	char ret = 0;
	//检测
	//printf("游戏开始！\n");
	// 创建棋盘数组
	char board[ROW][COL] = { '8' };
	//初始化棋盘
	Initboard(board,ROW,COL);
	//打印棋盘
	Printboard(board, ROW, COL);
	//玩家和电脑交替下棋直至有一方“三子一线”游戏结束
	while (1)
	{
		//玩家走
		Playermove(board,ROW,COL);
		//打印棋盘
		Printboard(board, ROW, COL);
		//胜负判断
		ret = Iswin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
		//电脑走
		Computermove(board);
		//打印棋盘
		Printboard(board, ROW, COL);
		//胜负判断
		ret = Iswin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢！\n");
	}
	if (ret == '#')
	{
		printf("电脑赢！\n");
	}
	if (ret == 'Q')
	{
		printf("平局！\n");
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int input = 0;
	do
	{
		//打印菜单，1 表示玩游戏，0 表示退出
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入！\n");
			break;
		}
	} while (input);
	return 0;
}