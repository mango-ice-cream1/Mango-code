#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

#include<vector>

using namespace std;
#include<algorithm>


//STL----standard template library
//六大组件：容器、算法、迭代器、仿函数、适配器、空间配置器

int mian()
{
	vector<int> v;
	//尾插法插入数据
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