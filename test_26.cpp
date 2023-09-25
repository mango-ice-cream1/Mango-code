#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<stdio.h>

//void test01()
//{
//	
//}
//
//
//
class Person
{
public:

	Person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}

	 void show_info();

	int m_age;
	string m_name;
};


int main()
{
	Person p1("张三", 20);
	Person p2("李四", 20);
	//p1.show_info();
	//p2.show_info();
	cout << sizeof(p1) << endl;
	return 0;
}
//
//inline void Person::show_info()
//{
//	cout << m_name << endl;
//	cout << m_age << endl;
//}
////
//class Apple
//{
//public:
//	Apple(int a, int b)
//	{
//		this->m_A;
//		this->m_B;
//	}
//	void Show_info()
//	{
//		cout << "m_A = " << this->m_A << endl;
//		cout << "m_B = " << this->m_B << endl;
//		this->m_A++;
//		this->m_B++;
//	}
//
//	int m_A;
//	int m_B;
//};
////int main()
////{
////	Person p1("张三", 20);
////	p1.show_info();
////	//test01();
////	return 0;
////}
//
//
//#define SIZE 100
//
//int main()
//{
//	int quantity = 0;
//	int price = 0;
//	char department[SIZE] = { 0 };
//
//	scanf("%d%d", &quantity, &price);
//	scanf("%s", department);
//	printf("quantity = %d , price = %d \n", quantity, price);
//	printf("department = %s\n", department);
//	return 0;
//}

//class Person
//{
//public:
//	void Set(int a, int b=5, int c = 199)
//	{
//		m_a = a;
//		m_b = b;
//		m_c = c;
//	}
//	void show_info()
//	{
//		cout << m_a << endl
//			<< m_b << endl
//			<< m_c << endl;
//	}
//	int m_a;
//	int m_b;
//	int m_c;
//};
//
//
//int main()
//{
//	Person p1;
//	p1.Set(3);
//	p1.show_info();
//	return 0;
//}

