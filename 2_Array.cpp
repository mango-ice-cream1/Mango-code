

#include<iostream>
using namespace std;

void InputMatrix2(int row, int col, int** matrix) 
{
	cout << "Please input the elements of the matrix: "<<endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> matrix[i][j];
		}
	}
	cout << "-----------------------------------------------" << endl;
}

void OutputMatrix2(int row, int col, int** matrix)
{
	cout << "The original matrix you input is:" << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << "-----------------------------------------------" << endl;
}



void TransposeMatrix2(int row, int col, int** matrix)
{
	if (row != col)
	{
		int** matrix2 = new int* [col];
		if (matrix2 == NULL)
		{
			cout << "�ڴ濪��ʧ�ܣ�" << endl;
			//cout << strerror(errno) << endl;
			exit(-2);
		}
		for (int i = 0; i < col; i++)
		{
			//�˴��Ͳ��Զ�̬�ڴ濪�����ж���
			matrix2[i] = new int[row];
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				matrix2[j][i] = matrix[i][j];
			}
		}
		cout << "The transposed matrix is:" << endl;
		OutputMatrix2(col, row, matrix2);
	}
	else
	{
		for (int i = 0; i < row - 1; i++)
		{
			for (int j = i + 1; j < col; j++)
			{
				int temp = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = temp;
			}
		}
		OutputMatrix2(row, col, matrix);
	}


	cout << "-----------------------------------------------" << endl;
}

