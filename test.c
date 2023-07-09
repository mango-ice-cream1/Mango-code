#include"game.h"
#include<stdlib.h>
#include<time.h>

void game()
{
	char ret = 0;
	//���
	//printf("��Ϸ��ʼ��\n");
	// ������������
	char board[ROW][COL] = { '8' };
	//��ʼ������
	Initboard(board,ROW,COL);
	//��ӡ����
	Printboard(board, ROW, COL);
	//��Һ͵��Խ�������ֱ����һ��������һ�ߡ���Ϸ����
	while (1)
	{
		//�����
		Playermove(board,ROW,COL);
		//��ӡ����
		Printboard(board, ROW, COL);
		//ʤ���ж�
		ret = Iswin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
		//������
		Computermove(board);
		//��ӡ����
		Printboard(board, ROW, COL);
		//ʤ���ж�
		ret = Iswin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ��\n");
	}
	if (ret == '#')
	{
		printf("����Ӯ��\n");
	}
	if (ret == 'Q')
	{
		printf("ƽ�֣�\n");
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int input = 0;
	do
	{
		//��ӡ�˵���1 ��ʾ����Ϸ��0 ��ʾ�˳�
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("����������������룡\n");
			break;
		}
	} while (input);
	return 0;
}