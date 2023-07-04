

#include<stdlib.h>
#include<stdio.h>

#define MAX 100


//顺序栈的定义
typedef struct
{
	int* base;
	int* top;
	int stacksize;
}SqStack;

//链栈的定义
typedef struct Snode
{
	int data;
	struct Snode* next;
}Snode;

//顺序队列的定义
typedef struct Queue
{
	int* array;
	int front;
	int rear;
}SqQueue;

//链队列的定义
//节点定义
typedef struct Qnode
{
	int data;
	struct Qnode* next;
}Qnode;
//队列定义
typedef struct
{
	Qnode* front;
	Qnode* rear;
}LinkQueue;



//栈的初始化
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

//创建顺序栈
SqStack* CreateStack(SqStack* s)
{
	int i= 0;
	for (i = 0; i < 10; i++)
	{
		*(s->top++) = i + 1;
	}
	return s;
}

//清空顺序栈
SqStack* ClearStack(SqStack* s)
{
	if (s->base != NULL)
	{
		s->top = s->base;
	}
	return s;
}

//销毁顺序栈
SqStack* DestroyStack(SqStack* s)
{
	free(s->base);
	s->top = s->base = NULL;
	s->stacksize = 0;
	return s;
}


//顺序栈的入栈
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

//顺序栈的出栈
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

//链栈的初始化
Snode* InitSnode(Snode* s)
{
	s = NULL;
	return s;
}

//创建链栈
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

//链栈的入栈(头插法)
Snode* PushSnode(Snode* s, int e)
{
	Snode* p = NULL;
	p->data = e;
	p->next = s->next;
	s->next = p;
	return s;
}


//链栈的出栈(假如有头节点)
Snode* PopSnode(Snode* s)
{
	int e = 0;
	Snode* p = NULL;
	p = s;
	e = s->next->data;
	printf("\n删除的元素是：%d\n", e);
	s = s->next;
	free(p);
	return s;
}

//链栈的输出
void ShowSnode(Snode* s)
{
	Snode* p = s->next;
	while (p!=NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}


//队列的初始化
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

//创建一个队列
SqQueue* CreateQueue(SqQueue* Q)
{

}

//求队列长度(循环队列的长度比队列实际长度小1
//因为牺牲了一个元素空间)
int Qlength(SqQueue* Q)
{
	return (Q->rear + MAX - Q->front) % MAX;
}

//循环队列的入队
SqQueue* EnQueue(SqQueue* Q, int e)
{
	//判断是否队满
	if ((Q->rear + 1) % MAX == Q->front)
	{
		return 0;
	}
	Q->array[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAX;
	return Q;
}

//循环队列的出队
SqQueue* DeQueue(SqQueue* Q)
{
	int e = 0;
	//判断是否队空
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
	
	//链栈的创建
	Snode s1 = { 0,NULL };
	Snode* s = &s1;
	CreateSnode(s);
	ShowSnode(s);
	return 0;
}