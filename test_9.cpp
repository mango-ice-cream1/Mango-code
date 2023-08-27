


#include<stdio.h>
#include<iostream>


using namespace std;


#define MAX 100

typedef int Data_type;
typedef int Weight_type;


//�߽ṹ:ͷ�ڵ��±�+ָ����һ�ߵ�ָ����+Ȩֵ��ֵ��
typedef struct ArcsNode
{
	int sub;              //ͷ�ڵ��±�
	struct ArcsNode* next;        //ָ����һ�ߵ�ָ����
	Weight_type weight;   //Ȩֵ��ֵ��
}ArcsNode;



//����ṹ ������+ָ��������ͷ�ڵ㣩

typedef struct
{
	Data_type data;        //����������� 
	ArcsNode* first;   //���ӱ߽ڵ��ָ����
}VexsNode;




//����ͼ���ڽӱ�ṹ:ͷ�ڵ�����+������+����
typedef struct
{
	VexsNode VexsArray[MAX];
	int vexs_num, arcs_num;
}A_Graph;


//���Ҷ���λ��
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
	//���ն������ͱ���
	printf("�����붥������\n");
	cin >> G.vexs_num;
	printf("\n�����������\n");
	cin >> G.arcs_num;

	//���������(�˴�д�ý�Ϊ�ֲ�)
	for (int i = 0; i < G.vexs_num; i++)
	{
		cin >> G.VexsArray[i].data;
		G.VexsArray[i].first = NULL;
	}

	//�����ڽӱ�
	for (int k = 0; k < G.arcs_num; k++)
	{
		int i = 0;
		int j = 0;
		Data_type v1 = { 0 };
		Data_type v2 = { 0 };
		Weight_type w = 0;
		printf("��������������Ϣ��\n");
		cin >> v1 >> v2;
		i = LocateVexs(G, v1);
		j = LocateVexs(G, v2);
		printf("\n������ߵ�Ȩֵ��\n");
		cin >> w;
		
		//�����±߽ڵ�
		ArcsNode* p1 = (ArcsNode*)malloc(sizeof(ArcsNode));
		p1->sub = j;
		p1->weight = w;
		p1->next = G.VexsArray[i].first;
		G.VexsArray[i].first = p1;

		//�����ڶ����±߽ڵ���о������
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