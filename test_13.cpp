

#include<stdio.h>


typedef struct
{
	int* L, * R;
	int length;
}BTree;


int IsSon(BTree B, int u, int v)
{
	if (u == v)return 0;
	int flag = 0;
	int temp = u;
	//if (u == 0)return 0;
	//if (u == v)
	//{
	//	printf("u��v������");
	//}
	//IsSon(B, B.L[u], v);
	//IsSon(B, B.R[u], v);

	while(u != 0 && flag==0)
	{
		u = B.L[u];
		if (u == v)
		{
			flag = 1;
		}
	}
	u = temp;
	while (u != 0 && flag==0)
	{
		u = B.R[u];
		if (u == v)
		{
			flag = 1;
		}
	}

	return flag;
}

BTree Create_BTree(BTree B)
{
	//����������L�����ʾ���Һ�����R�����ʾ�����ݽṹ������
}



int main()
{
	BTree B = { 0 };
	scanf("%d", &B.length);
	B = Create_BTree(B);
	int u = 0;
	int v = 0;
	scanf("%d%d", &u, &v);
	IsSon(B, u, v);
	return 0;
}