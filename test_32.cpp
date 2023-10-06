#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<errno.h>
#include<stdlib.h>
using namespace std;

#define MAX 100




typedef struct ListNode
{
	int data;//数据域
	struct ListNode* next;
}Node;

typedef struct Array
{
	Node* array;
	int length;
}*Array;


void InputMatrix(int row, int col, int** matrix)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			//cin >> matrix[i][j];
			matrix[i][j] = 20;
		}
	}
}


void OutputMatrix(int row, int col, int** matrix)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << matrix[i][j]<<" ";
		}
		cout << endl;
	}
}

void MultiplyMatrix(int row, int col, int** matrix)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			//cin >> matrix[i][j];
			matrix[i][j] *= 10;
		}
	}
}

//int main()
//{
//	int row = 0;
//	int col = 0;
//	cout << "Please input two dimensions of the Matrix: ";
//	cin >> row >> col;
//	int** matrix = (int**)malloc(sizeof(int*) * row);
//	
//	for (int i = 0; i < row; i++)
//	{
//		matrix[i] = new int[col];
//		//matrix[i] = malloc(col*sizeof(int));
//	}
//
//	if (matrix == NULL) {
//		//cout << "动态分配空间失败，请检查程序！" << endl;
//		cout << strerror(errno) << endl;
//		exit(1);
//	}
//	InputMatrix(row, col, matrix);
//	cout << "---------------------------------------------------------" << endl;
//	OutputMatrix(row, col, matrix);
//	char flag = 'y';
//	while (tolower(flag) == 'y') {
//		cout << "---------------------------------------------------------" << endl;
//		MultiplyMatrix(row, col, matrix);
//		cout << "after mutiplying: " << endl;
//		OutputMatrix(row, col, matrix);
//		cout << "Do you want to continue to multiply the matrix?(Y/N)";
//		cin >> flag;
//	}
//	for (int i = 0; i < row; i++) { free(matrix[i]); }
//	free(matrix);
//	return 0;
//}



void InputArray(int row, int col, Array ListArray)
{
	for (int i = 0; i < col; i++)
	{
		Node* t = &ListArray->array[i];
		for (int j = 0; j < col; j++)
		{
			Node* p = new Node();
			p->next = NULL;
			int ret = 0;
			cin >> ret;
			p->data = ret;
			//cin >> p->data;//不对数据进行检测直接放入，存在风险
			t->next = p;
			t = t->next;
		}
	}
}

//OutputArray(row, col, ListArray);

//int main()
//{
//	int row = 0;
//	int col = 0;
//	cout << "Please input two dimensions of the Matrix: ";
//	Array ListArray = { 0 };
//	ListArray->array = new Node[row];
//	ListArray->length = row;
//
//	InputArray(row, col, ListArray);
//	//OutputArray(row, col, ListArray);
//
//
//	return 0;
//}
