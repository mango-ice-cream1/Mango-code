
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>

using namespace std;

typedef int KeyType;

typedef struct
{
	KeyType key;
	int* List;
}ElemType;


typedef struct
{
	ElemType* R;
	int length;
}SSTable;



//�ڱ������ٱȽϴ������ӿ�����
int Search(SSTable S, int key)
{
	S.R[0].key = key;
	int i = 0;
	for (i = S.length; key != S.R[i].key; i--);
	return i;
}


int main()
{
	int ret = 0;
	srand((unsigned)time(NULL));
	SSTable S = { 0 };
	int n = 16;
	S.length = n;
	S.R = (ElemType*)malloc(S.length * sizeof(ElemType));
	for (int i = 1; i <= S.length-1; i++)
	{
		S.R[i].key = rand() % 100 + 1;
	}
	for (int i = 1; i <= S.length - 1; i++)
	{
		printf("%d ", S.R[i].key);
	}
	printf("\n������Ҫ���ҵ����֣�");
	cin >> ret;
	int m=Search(S, ret);
	if (m != 0)
	{
		printf("�ҵ��ˣ��������е�������%d,:)", m);
	}
	else
	{
		printf("\nû�ҵ���");
	}

	return 0;
}


