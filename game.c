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

//���̳�ʼ��
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

//��ӡ����
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

//�����
void Playermove(char board[][COL],int row,int col)
{
	printf("����ߣ�\n");
	while(1)
	{
		int x = 0;
		int y = 0;
		printf("����������λ��:��\n");
		scanf("%d %d", &x, &y);
		if ((x > 0 && x <= row) && (y > 0 && y <= col))
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}	
			else
				printf("��λ�ñ�ռ��\n");
		}
		else
			printf("����������������룡\n");
	}
}

//������
void Computermove(char board[][COL])
{
	printf("�����ߣ�\n");
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

//ʤ���ж�����״̬
// ���Ӯ *
// ����Ӯ #
// ƽ��   Q
// ��Ϸ���� C

//�ж������Ƿ�����
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
				return 0;//����0��ʾû��
			}
		}
	}
	return 1;//����1��ʾ����
}
char Iswin(char board[][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//���жϣ���ɨ�裩
	for (i = 0; i < row; i++)
	{
		if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}

	//���жϣ���ɨ�裩
	for (j = 0; j < col; j++)
	{
		if ((board[0][j] == board[1][j]) && (board[1][j] == board[2][j]) && board[0][j] != ' ')
		{
			return board[0][j];
		}
	}

	//б45��ʮ���ж�
	if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && board[0][0] != ' ')
	{
		return board[0][0];
	}
	if ((board[2][0] == board[1][1]) && (board[1][1] == board[0][2]) && board[2][0] != ' ')
	{
		return board[2][0];
	}

	//ƽ���ж�
	if (1 == IsFull(board, ROW, COL))
	{
		return 'Q';
	}
	//��Ϸ����
	return 'C';
}
