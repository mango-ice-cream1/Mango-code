#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

#include<vector>

using namespace std;
#include<algorithm>


//STL----standard template library
//����������������㷨�����������º��������������ռ�������

int mian()
{
	vector<int> v;
	//β�巨��������
	for (int i = 0; i < 5; i++)
	{
		v.push_back(i+1);
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	return 0;
}