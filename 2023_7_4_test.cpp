

#include<stdlib.h>
#include<stdio.h>

#define MAX 100


//˳��ջ�Ķ���
typedef struct
{
	int* base;
	int* top;
	int stacksize;
}SqStack;

//��ջ�Ķ���
typedef struct Snode
{
	int data;
	struct Snode* next;
}Snode;

//˳����еĶ���
typedef struct Queue
{
	int* array;
	int front;
	int rear;
}SqQueue;

//�����еĶ���
//�ڵ㶨��
typedef struct Qnode
{
	int data;
	struct Qnode* next;
}Qnode;
//���ж���
typedef struct
{
	Qnode* front;
	Qnode* rear;
}LinkQueue;



//ջ�ĳ�ʼ��
SqStack* InitStack(SqStack* s)
{
	s->base = (int*)malloc( MAX*sizeof(int) );
	if (s->base == NULL)
	{
		return 0;
	}

	s->top = s->base;
	s->stacksize = MAX;
	return s;
}

//����˳��ջ
SqStack* CreateStack(SqStack* s)
{
	int i= 0;
	for (i = 0; i < 10; i++)
	{
		*(s->top++) = i + 1;
	}
	return s;
}

//���˳��ջ
SqStack* ClearStack(SqStack* s)
{
	if (s->base != NULL)
	{
		s->top = s->base;
	}
	return s;
}

//����˳��ջ
SqStack* DestroyStack(SqStack* s)
{
	free(s->base);
	s->top = s->base = NULL;
	s->stacksize = 0;
	return s;
}


//˳��ջ����ջ
SqStack* Push(SqStack* s, int e)
{
	if (s->top - s->base == s->stacksize)
	{
		return 0;
	}
	*(s->top) = e;
	s->top++;
	return s;
}

//˳��ջ�ĳ�ջ
SqStack* Pop(SqStack* s)
{
	int e = 0;
	if ((s->top == s->base))
	{
		return 0;
	}
	e = *(s->top);
	s->top--;
	return s;
}

void ShowStack(SqStack* s)
{
	
	SqStack* p= s;
	while(p->top != p->base)
	{
		printf("%d ", *(--p->top));
	}
}

//��ջ�ĳ�ʼ��
Snode* InitSnode(Snode* s)
{
	s = NULL;
	return s;
}

//������ջ
Snode* CreateSnode(Snode* s)
{
	Snode* p = NULL;
	int i = 0;
	while (i < 10)
	{
		p = (Snode*)malloc(sizeof(Snode));
		p->data = i + 1;
		p->next = s->next;
		s->next = p;
		i++;
	}
	return s;
}

//��ջ����ջ(ͷ�巨)
Snode* PushSnode(Snode* s, int e)
{
	Snode* p = NULL;
	p->data = e;
	p->next = s->next;
	s->next = p;
	return s;
}


//��ջ�ĳ�ջ(������ͷ�ڵ�)
Snode* PopSnode(Snode* s)
{
	int e = 0;
	Snode* p = NULL;
	p = s;
	e = s->next->data;
	printf("\nɾ����Ԫ���ǣ�%d\n", e);
	s = s->next;
	free(p);
	return s;
}

//��ջ�����
void ShowSnode(Snode* s)
{
	Snode* p = s->next;
	while (p!=NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}


//���еĳ�ʼ��
SqQueue* InitQueue(SqQueue* Q)
{
	Q->array = (int*)malloc(MAX * sizeof(int));
	if (Q->array == NULL)
	{
		return 0;
	}
	Q->front = Q->rear = 0;
	return Q;
}

//����һ������
SqQueue* CreateQueue(SqQueue* Q)
{

}

//����г���(ѭ�����еĳ��ȱȶ���ʵ�ʳ���С1
//��Ϊ������һ��Ԫ�ؿռ�)
int Qlength(SqQueue* Q)
{
	return (Q->rear + MAX - Q->front) % MAX;
}

//ѭ�����е����
SqQueue* EnQueue(SqQueue* Q, int e)
{
	//�ж��Ƿ����
	if ((Q->rear + 1) % MAX == Q->front)
	{
		return 0;
	}
	Q->array[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAX;
	return Q;
}

//ѭ�����еĳ���
SqQueue* DeQueue(SqQueue* Q)
{
	int e = 0;
	//�ж��Ƿ�ӿ�
	if (Q->front == Q->rear)
	{
		return 0;
	}
	e = Q->array[Q->front];
	Q->front = (Q->front + 1) % MAX;
	return Q;
}


int main()
{
	/*SqStack s1 = {NULL,NULL,100};
	SqStack* s =&s1 ;
	s =InitStack(s);
	s = CreateStack(s);
	ShowStack(s);*/
	
	//��ջ�Ĵ���
	Snode s1 = { 0,NULL };
	Snode* s = &s1;
	CreateSnode(s);
	ShowSnode(s);
	return 0;
}