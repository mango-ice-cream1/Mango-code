
#include<iostream>

using namespace std;

//左移<<运算符重载

class Person
{
	friend ostream& operator<<(ostream& cout, Person& p);
public:
	Person(int a, int b)
	{
		m_A = a;
		m_B = b;
	}

private:
	int m_A;
	int m_B;
};

ostream& operator<<(ostream& cout, Person& p)
{
	cout << "p.m_A= " << p.m_A << "p.m_B= " << p.m_B;
	return cout;
}



//void test01()
//{
//	Person p1(10, 10);
//	cout << p1 << endl <<"hello world!" << endl;
//}

class MyInteger
{
	friend ostream& operator<<(ostream& cout, MyInteger myint);
public:
	MyInteger()
	{
		my_int = 0;
	}

	//前置++重载
	MyInteger& operator++()
	{
		my_int++;
		return *this;
	}
	//后置++重载
	MyInteger operator++(int)
	{
		MyInteger temp = *this;
		this->my_int++;
		return temp;
	}


private:
	int my_int;
};

ostream& operator<<(ostream& cout, MyInteger myint)
{
	cout << "my_int= " << myint.my_int;
	return cout;
}


void test01()
{
	MyInteger myint;
	cout << ++(++myint) << endl;
}

void test02()
{
	MyInteger myint;
	cout << myint++ << endl;
	cout << myint << endl;
}

int main()
{
	//test01();
	test02();
	return 0;
}


