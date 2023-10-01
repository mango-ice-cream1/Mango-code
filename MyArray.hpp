#pragma once

#include<string>
#include<iostream>
using namespace std;

template<class T>
class MyArray
{
public:
	//���캯��
	MyArray(int capacity)
	{
		//cout << "MyArray�Ĺ��캯������" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[capacity];
	}

	//��������
	MyArray(const MyArray& arr)
	{
		//cout << "MyArray�Ŀ������캯������" << endl;
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

	//����operator=
	MyArray& operator=(const MyArray &arr)
	{
		//cout << "MyArray������operator=��������" << endl;
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

	//β�巨
	void Push_Back(const T& val)
	{
		if (this->m_Capacity == this->m_Size)
		{
			cout << "����ռ�������" << endl;
			return;
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}

	//βɾ��
	void Pop_Back()
	{
		if (this->m_Size == 0)
		{
			cout << "�����Ѿ�Ϊ��" << endl;
			return;
		}
		this->m_Size--;
	}

	//����operator[]
	T& operator[](const int index)
	{
		return this->pAddress[index];
	}

	//��ȡ��������
	int getCapacity()
	{
		return this->m_Capacity;
	}

	//��ȡ�����С
	int getSize()
	{
		return this->m_Size;
	}

	//��������
	~MyArray()
	{
		//cout << "MyArray��������������" << endl;
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

	int m_Capacity;//��������

	int m_Size;    //�����С
};