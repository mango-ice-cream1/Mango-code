

//#include<stdio.h>
//#include<stdlib.h>


#include <string>
#include<iostream>

using namespace std;


//class building
//{
//	friend class GoodGay;
//public:
//	building();
//
//public:
//	string SittingRoom;
//
//private:
//	string BedRoom;
//
//};
//class GoodGay
//{
//public:
//	GoodGay();//���캯��
//	void visit();
//
//	//����
//	building* Building;
//};
//
////��֮��ʵ�����ں���
//GoodGay::GoodGay()
//{
//	Building = new building;
//}
//
//void GoodGay::visit()
//{
//	cout << "�û��ѣ����ڷ��ʣ�" << Building->SittingRoom << endl;
//	cout << "�û��ѣ����ڷ��ʣ�" << Building->BedRoom << endl;
//}
//
//
//building::building()
//{
//	SittingRoom = "����";
//	BedRoom = "����";
//}
//
//void test01()
//{
//	GoodGay gg;
//	gg.visit();
//}
//
//int main()
//{
//	test01();
//	return 0;
//}



class Person
{
public:
	Person operator+(Person &p)
	{
		Person temp;
		temp.m_A = this->m_A + p.m_A;
		temp.m_B = this->m_B + p.m_B;
		return temp;
	}
public:
	int m_A;
	int m_B;
};


//Person operator+(Person & p1, Person & p2)
//{
//	Person temp;
//	temp.m_A = p1.m_A + p2.m_A;
//	temp.m_B = p1.m_B + p2.m_B;
//	return temp;
//}


void test01()
{
	Person p1;
	p1.m_A = 10;
	p1.m_B = 10;
	Person p2;
	p2.m_A = 10;
	p2.m_B = 10;
	Person p3 = p1 + p2;
	//Person p3 = p1.operator+(p2);
	cout << "p3.m_A=" << p3.m_A << endl;
	cout << "p3.m_B=" << p3.m_B << endl;
}
int main()
{
	test01();
	return 0;
}

