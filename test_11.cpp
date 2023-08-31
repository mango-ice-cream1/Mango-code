
#include<stdio.h>


typedef struct BsNode
{
	int data;
	struct BsNode* Lchild;
	struct BsNode* Rchild;
}BsNode;


BsNode* Search(BsNode* T, int key)
{
	if (T == NULL)return 0;
	if (T->data == key)return T;
	else if (key > T->data)
	{
		return Search(T->Rchild, key);
	}
	else
	{
		return Search(T->Lchild, key);
	}
}

int main()
{

	return 0;
}