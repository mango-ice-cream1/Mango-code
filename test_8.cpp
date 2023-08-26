#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<limits.h>
#include <iostream>

using namespace std;

//创建无向图的邻接矩阵表示

//定义图的数据结构
#define MAX_SIZE 100
typedef char Vexs_type;
typedef int Arcs_type;

typedef struct 
{
	Vexs_type vexs[MAX_SIZE];//顶点表
	Arcs_type arcs[MAX_SIZE][MAX_SIZE];//邻接矩阵
	int vexs_num, arcs_num;//顶点数，边数
}Graph;


//顶点位置查找
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

//创建无向图
Graph Create_UndirectedGraph(Graph G)
{
	//请求输入顶点数目和边数（未检测输入数字的正确性）
	printf("请输入顶点数：\n");
	scanf("%d", &G.vexs_num);
	printf("\n请输入边数：\n");
	scanf("%d", &G.arcs_num);

	//依次输入顶点信息，存入顶点数组
	printf("\n请依次输入顶点信息：\n");
	for (int i = 0; i < G.vexs_num; i++)
	{
		scanf("%d", &G.vexs[i]);
	}

	//初始化邻接矩阵
	for (int i = 0; i < G.vexs_num; i++)
	{
		for (int j = 0; j < G.arcs_num; j++)
		{
			G.arcs[i][j] = INT_MAX;
		}
	}

	//为相关联的边赋值
	for (int k = 0; k < G.vexs_num; k++)
	{
		int i = 0;
		int j = 0;
		Vexs_type v1 = 0;
		Vexs_type v2 = 0;
		Arcs_type w = 0;
		printf("请输入两个顶点信息：");
		//此处体现出c语言的输入输出对于数据格式的限制，需知道数据类型才能完成输入
		//此处权当是char类型
		//没有通过，此处用了C++的cin输入
		cin >> v1 >> v2;
		printf("请输入边的权值：");
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

