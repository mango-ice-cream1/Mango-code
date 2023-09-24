
#include<iostream>
using namespace std;
#include<string>

template<typename T>
void my_swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<class T1,class T2>
class Person
{
public:
	Person(T1 name, T2 age);

	void show_info();

	void test01();

	T1 m_name;
	T2 m_age;
};

template<class T1,class T2>
Person<T1,T2>::Person(T1 name,T2 age)
{
	this->m_name = name;
	this->m_age = age;
}

template<class T1, class T2>
void Person<T1, T2>::show_info()
{
	cout << "m_name = " << m_name << endl;
	cout << "m_age = " << m_age << endl;
}


template<class T1, class T2>
void Person<T1,T2>::test01()
{
	cout << "T1的类型是 " << typeid(T1).name() << endl;
	cout << "T2的类型是 " << typeid(T2).name() << endl;
}

int main()
{
	//int a = 10;
	//int b = 20;
	//char a = 'a';
	//char b = 'b';
	//my_swap(a, b);
	//cout << "a = " << a << endl;
	//cout << "b = " << b << endl;

	Person<string, int> p1("小王",20);
	p1.show_info();
	p1.test01();

	return 0;
}