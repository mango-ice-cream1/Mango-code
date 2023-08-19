#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

//˳��洢�ṹ�Ĺ��������ڵ�ṹ
typedef struct
{
	int weight;//��ʾ�ڵ�Ȩ��
	int parent, lch, rch;//˫�׺ͺ��ӽڵ��λ��
}Huffuman_node,*HuffumanTree;



HuffumanTree CreateHuffumanTree(HuffumanTree H, int n)
{
	if (n <= 1)return 0;
	int m = 2 * n - 1;
	H = (HuffumanTree)malloc((static_cast<unsigned long long>(m) + 1) * sizeof(Huffuman_node));
	for (int i = 1; i <= m; i++)
	{
		H[i].parent = 0;
		H[i].lch = 0;
		H[i].rch = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> H[i].weight;
	}
	for (int i = n + 1; i < m; i++)
	{
		int s1 = 0;
		int s2 = 0;
		//�˴���һ����������ѡ��ɭ����Ȩֵ��С�Ľڵ�
		//Select();��󷵻����ڵ��λ��s1��s2��
		H[s1].parent = i;
		H[s2].parent = i;
		H[i].lch = s1;
		H[i].rch = s2;
		H[i].weight = H[s1].weight + H[s2].weight;
	}
	return H;
}


int main()
{
	int i = 0;
	HuffumanTree H = NULL;
	H=(HuffumanTree)malloc(16 * sizeof(Huffuman_node));
	H = CreateHuffumanTree(H , 8);

	return 0;
}