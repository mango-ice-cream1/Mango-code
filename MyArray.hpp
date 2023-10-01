#pragma once

#include<string>
#include<iostream>
using namespace std;

template<class T>
class MyArray
{
public:
	//构造函数
	MyArray(int capacity)
	{
		//cout << "MyArray的构造函数调用" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[capacity];
	}

	//拷贝构造
	MyArray(const MyArray& arr)
	{
		//cout << "MyArray的拷贝构造函数调用" << endl;
		//if (this->pAddress != NULL)
		//{
		//	delete[]pAddress;
		//	pAddress = NULL;
		//}
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Size];
		for (int i = 0; i < arr.m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//重载operator=
	MyArray& operator=(const MyArray &arr)
	{
		//cout << "MyArray的重载operator=函数调用" << endl;
		if (this->pAddress != NULL)
		{
			delete[]this->pAddress;
			pAddress = NULL;
		}
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Size];
		for (int i = 0; i < arr.m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}

	//尾插法
	void Push_Back(const T& val)
	{
		if (this->m_Capacity == this->m_Size)
		{
			cout << "数组空间已满！" << endl;
			return;
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}

	//尾删法
	void Pop_Back()
	{
		if (this->m_Size == 0)
		{
			cout << "数组已经为空" << endl;
			return;
		}
		this->m_Size--;
	}

	//重载operator[]
	T& operator[](const int index)
	{
		return this->pAddress[index];
	}

	//获取数组容量
	int getCapacity()
	{
		return this->m_Capacity;
	}

	//获取数组大小
	int getSize()
	{
		return this->m_Size;
	}

	//析构函数
	~MyArray()
	{
		//cout << "MyArray的析构函数调用" << endl;
		if (pAddress != NULL)
		{
			delete[]this->pAddress;
			pAddress = NULL;
		}
		//this->m_Capacity = 0;
		//this->m_Size = 0;
	}

private:
	T* pAddress;

	int m_Capacity;//数组容量

	int m_Size;    //数组大小
};