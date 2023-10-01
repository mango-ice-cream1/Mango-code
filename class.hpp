#pragma once

#include<iostream>
using namespace std;

template<class T1, class T2>
class Person
{
public:
	Person(T1 name, T2 age);
	//{
	//	this->m_name = name;
	//	this->m_age  = age;
	//}

	void Show_info();
	//{
	//	cout << "�����ǣ�" << this->m_name << "  ���䣺" << this->m_name << endl;
	//}
	T1 m_name;
	T2 m_age;
};

template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
	this->m_name = name;
	this->m_age = age;
}


template<class T1, class T2>
void Person<T1, T2>::Show_info()
{
	cout << "�����ǣ�" << this->m_name << "  ���䣺" << this->m_age << endl;
}