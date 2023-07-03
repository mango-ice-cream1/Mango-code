#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

typedef struct Node
{
	int data;
	Node* next;
}Node;


Node* Create(Node* L)
{
	int i = 0;
	Node* p = NULL;
	Node* t = NULL;
	L = (Node*)malloc(sizeof(Node));
	L->data = 0;
	L->next = L;
	t = L;
	for (i = 0; i < 10; i++)
	{
		p = (Node*)malloc(sizeof(Node));
		if (p == NULL)
		{
			printf("\n%s\n", strerror(errno));
		}
		else
		{
			p->data = i + 1;
			p->next = L;
			t->next = p;
			t = p;
		}
	}
	return t;
}

void ShowList(Node* L)
{
	Node* p = L->next->next;
	while (p != L->next)
	{
		printf("%d ", p->data);
		p = p->next;
	}	
}

Node* Connect(Node* La, Node* Lb)
{
	Node* t = NULL;
	t = La->next;
	La->next = Lb->next->next;
	free(Lb->next);
	Lb->next = t;
	return Lb;
}
int main()
{
	Node* List = NULL;
	List=Create(List);
	Node* List2 = NULL;
	List2 = Create(List2);
	ShowList(List);
	printf("\n");
	ShowList(List2);
	printf("\n");
	Node* ret = Connect(List, List2);
	ShowList(ret);
	free(List);
	free(List2);
	return 0;
}