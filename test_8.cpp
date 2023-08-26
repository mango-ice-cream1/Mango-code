#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<limits.h>
#include <iostream>

using namespace std;

//��������ͼ���ڽӾ����ʾ

//����ͼ�����ݽṹ
#define MAX_SIZE 100
typedef char Vexs_type;
typedef int Arcs_type;

typedef struct 
{
	Vexs_type vexs[MAX_SIZE];//�����
	Arcs_type arcs[MAX_SIZE][MAX_SIZE];//�ڽӾ���
	int vexs_num, arcs_num;//������������
}Graph;


//����λ�ò���
int Locate_vexs(Graph G, Vexs_type v1)
{
	for (int i = 0; i < G.vexs_num; i++)
	{
		if (v1 == G.vexs[i])
		{
			return i;
		}
	}
	return -1;
}

//��������ͼ
Graph Create_UndirectedGraph(Graph G)
{
	//�������붥����Ŀ�ͱ�����δ����������ֵ���ȷ�ԣ�
	printf("�����붥������\n");
	scanf("%d", &G.vexs_num);
	printf("\n�����������\n");
	scanf("%d", &G.arcs_num);

	//�������붥����Ϣ�����붥������
	printf("\n���������붥����Ϣ��\n");
	for (int i = 0; i < G.vexs_num; i++)
	{
		scanf("%d", &G.vexs[i]);
	}

	//��ʼ���ڽӾ���
	for (int i = 0; i < G.vexs_num; i++)
	{
		for (int j = 0; j < G.arcs_num; j++)
		{
			G.arcs[i][j] = INT_MAX;
		}
	}

	//Ϊ������ı߸�ֵ
	for (int k = 0; k < G.vexs_num; k++)
	{
		int i = 0;
		int j = 0;
		Vexs_type v1 = 0;
		Vexs_type v2 = 0;
		Arcs_type w = 0;
		printf("����������������Ϣ��");
		//�˴����ֳ�c���Ե���������������ݸ�ʽ�����ƣ���֪���������Ͳ����������
		//�˴�Ȩ����char����
		//û��ͨ�����˴�����C++��cin����
		cin >> v1 >> v2;
		printf("������ߵ�Ȩֵ��");
		cin >> w;
		i = Locate_vexs(G, v1);
		j = Locate_vexs(G, v2);
		G.arcs[i][j] = w;
		G.arcs[j][i] = w;
	}
	return G;
}

int main()
{
	Graph G = { 0 };
	Create_UndirectedGraph(G);
	return 0;
}

