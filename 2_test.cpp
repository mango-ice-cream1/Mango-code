#define _CRT_SECURE_NO_WARNINGS 1

//#include <iostream>
//#include <ctype.h>
//#include <stdlib.h>
//#include"2_Array.h"
//using namespace std;



//顺序数组实现矩阵转置
//int main() 
//{
//    int row = 0;
//    int col = 0;
//    char flag = 'y';
//    while (tolower(flag) == 'y') 
//    {
//        cout << "Please input two dimensions of the matrix: ";
//        cin >> row >> col;
//        //开辟row行col列的二维数组
//        int** matrix = new int*[row];   
//        //int** matrix = (int**)malloc(row * sizeof(int*));
//        if (matrix == NULL)
//        {
//            cout << strerror(errno) << endl;
//            exit(-1);
//        }
//        for (int i = 0; i < row; i++)
//        {
//            matrix[i] = new int[col];
//            if (matrix[i] == NULL)
//            {
//                cout << strerror(errno) << endl;
//                exit(-1);
//            }
//        }
//
//        InputMatrix2(row, col, matrix);
//        OutputMatrix2(row, col, matrix);
//        TransposeMatrix2(row, col, matrix);
//        cout << "Do you want to continue to transpose the matrix?(Y/N)";
//        cin >> flag;
//
//        //清空内存
//        for (int i = 0; i < row; i++)
//        {
//            delete[]matrix[i];
//
//        }       
//            delete[]matrix;
//    }
//
//}


#include<iostream>
using namespace std;

//链表实现矩阵转置
typedef struct ListNode
{
	int data;
	struct ListNode* Row_ptr, *Col_ptr;
}Node;




int main()
{
	Node* ListArray = new Node({ 0 });
	int row = 0;
	int col = 0;
	ListArray->Col_ptr = NULL;

	Node* h = ListArray;

	cout << "请输入矩阵的元素" << endl;

	for (int i = 0; i < row; i++)
	{
		
		for (int j = 0; j < col; j++)
		{
			int ret = 0;
			cin >> ret;
			Node* t = new Node;
			t->data = ret;
			t->Col_ptr = NULL;
			p->Col_ptr = t;
			
		}

	}
	return 0;
}
