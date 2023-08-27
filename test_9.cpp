


#include<stdio.h>
#include<iostream>


using namespace std;


#define MAX 100

typedef int Data_type;
typedef int Weight_type;


//边结构:头节点下标+指向下一边的指针域+权值数值域
typedef struct ArcsNode
{
	int sub;              //头节点下标
	struct ArcsNode* next;        //指向下一边的指针域
	Weight_type weight;   //权值数值域
}ArcsNode;



//顶点结构 数据域+指针域（链表头节点）

typedef struct
{
	Data_type data;        //顶点的数据域 
	ArcsNode* first;   //连接边节点的指针域
}VexsNode;




//无向图的邻接表结构:头节点数组+顶点数+边数
typedef struct
{
	VexsNode VexsArray[MAX];
	int vexs_num, arcs_num;
}A_Graph;


//查找顶点位置
int LocateVexs(A_Graph G, Data_type u)
{
	for (int i = 0; i < G.vexs_num; i++)
	{
		if (u == G.VexsArray[i].data)
		{
			return i;
		}
	}
	return -1;
}




A_Graph CreateA_Gragh(A_Graph G)
{
	//接收顶点数和边数
	printf("请输入顶点数：\n");
	cin >> G.vexs_num;
	printf("\n请输入边数：\n");
	cin >> G.arcs_num;

	//构建顶点表(此处写得较为粗糙)
	for (int i = 0; i < G.vexs_num; i++)
	{
		cin >> G.VexsArray[i].data;
		G.VexsArray[i].first = NULL;
	}

	//构建邻接表
	for (int k = 0; k < G.arcs_num; k++)
	{
		int i = 0;
		int j = 0;
		Data_type v1 = { 0 };
		Data_type v2 = { 0 };
		Weight_type w = 0;
		printf("请输入两顶点信息：\n");
		cin >> v1 >> v2;
		i = LocateVexs(G, v1);
		j = LocateVexs(G, v2);
		printf("\n请输入边得权值：\n");
		cin >> w;
		
		//创建新边节点
		ArcsNode* p1 = (ArcsNode*)malloc(sizeof(ArcsNode));
		p1->sub = j;
		p1->weight = w;
		p1->next = G.VexsArray[i].first;
		G.VexsArray[i].first = p1;

		//创建第二个新边节点进行镜像操作
		ArcsNode* p2 = (ArcsNode*)malloc(sizeof(ArcsNode));
		p2->sub = i;
		p2->weight = w;
		p2->next = G.VexsArray[j].first;
		G.VexsArray[j].first = p2;
	}

	return G;
}

int main()
{
	A_Graph G = { 0 };
	G=CreateA_Gragh(G);
	return 0;
}