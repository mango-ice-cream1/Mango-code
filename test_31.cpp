
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<ctime>
#include<algorithm>
using namespace std;

//class Worker
//{
//public:
//	Worker(string name, int salary)
//	{
//		this->m_Name = name;
//		this->m_Salary = salary;
//	}
//
//	string m_Name;
//	int m_Salary;
//};
//
//void CreateWorker(vector<Worker>& v)
//{
//	
//	for (int i = 0; i < 10; i++)
//	{
//		string nameSeed = "ABCDEFGHIJ";
//
//		string name = "Ա��";
//		name += nameSeed[i];
//		int salary = rand() % 1000 + 1000;
//
//		Worker p(name, salary);
//
//		v.push_back(p);
//		
//	}
//}
//
//void SetGroup(vector<Worker>& v, multimap<int, Worker>& m)
//{
//	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		int ret = rand() % 3 + 1;
//		m.insert(make_pair(ret, *it));
//	}
//}
//
//void Show_info(multimap<int,Worker>& m)
//{
//	cout << "�߻����ţ�" << endl;
//	multimap<int, Worker>::iterator pos = m.find(1);
//	int index = m.count(1);
//	int i = 0;
//	for (; pos != m.end() && i < index; pos++, i++)
//	{
//		cout << "������" << pos->second.m_Name << "  н��:" << pos->second.m_Salary << endl;
//	}
//
//	cout << "--------------------------" << endl;
//	cout << "�������ţ�" << endl;
//	pos = m.find(2);
//	index = m.count(2);
//	i = 0;
//	for (; pos != m.end() && i < index; pos++, i++)
//	{
//		cout << "������" << pos->second.m_Name << "  н��:" << pos->second.m_Salary << endl;
//	}
//
//	cout << "--------------------------" << endl;
//	cout << "�з����ţ�" << endl;
//	pos = m.find(3);
//	index = m.count(3);
//	i = 0;
//	for (; pos != m.end() && i < index; pos++, i++)
//	{
//		cout << "������" << pos->second.m_Name << "  н��:" << pos->second.m_Salary << endl;
//	}
//}
//
//int main()
//{
//	srand((unsigned int)time(NULL));
//	vector<Worker> v;
//	CreateWorker(v);
//	//����
//	//for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
//	//{
//	//	cout << "������" << it->m_Name << "  н�ʣ�" << it->m_Salary << endl;
//	//}
//
//	multimap<int, Worker> m;
//	//��10��Ա������
//	SetGroup(v, m);
//
//	//����
//	//for (multimap<int, Worker>::iterator it = m.begin(); it != m.end(); it++)
//	//{
//	//	cout << "���ű�ţ�" << it->first << "  ������" << it->second.m_Name << "  н�ʣ�" << it->second.m_Salary << endl;
//	//}
//	Show_info(m);
//
//	return 0;
//}


void Print01(int val)
{
	cout << val << " ";
}


class Print02
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}

};

class Transform
{
public:
	int operator()(int val)
	{
		return val;
	}

};

class Person1
{
public:
	Person1(string name, int age)
	{
		this->m_name = name;
		this->m_age  = age;
	}
	//bool operator==(const Person1 &p)
	//{
	//	if (this->m_name == p.m_name && this->m_age == p.m_age)
	//	{
	//		return true;
	//	}
	//	else
	//	{
	//		return false;
	//	}
	//}

	string m_name;
	int m_age;
};


bool Compare_m(const Person1& p)
{
	if (p.m_age > 20)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool operator==(const Person1& p1, const Person1& p2)
{
	if (p1.m_name == p2.m_name && p1.m_age == p1.m_age)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool My_count(const Person1& p)
{
	if (p.m_age == 40)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	//vector<int> v;
	//for (int i = 0; i < 10; i++)
	//{
	//	v.push_back(i + 1);
	//}

	//for_each(v.begin(), v.end(), Print01);
	//cout << endl;

	//for_each(v.begin(), v.end(), Print02());
	//cout << endl;

	//vector<int> v2;
	//v2.resize(10);

	//transform(v.begin(), v.end(), v2.begin(), Transform());
	//for_each(v.begin(), v.end(), Print02());
	//cout << endl;

	//vector<int>::iterator pos = find(v.begin(), v.end(), 11);

	//if (pos != v.end())
	//{
	//	cout << "�ҵ���,����Ϊ��" << *pos << endl;
	//}
	//else
	//{
	//	cout << "û�ҵ�" << endl;
	//}

	//vector<Person1> v1;
	//Person1 p1("aaa", 10);
	//Person1 p2("bbb", 40);
	//Person1 p3("ccc", 30);
	//Person1 p4("ddd", 40);

	//v1.push_back(p1);
	//v1.push_back(p2);
	//v1.push_back(p3);
	//v1.push_back(p4);

	//vector<Person1>::iterator pos = find(v1.begin(), v1.end(), p1);

	//if (pos != v1.end())
	//{
	//	cout << "�ҵ��ˣ�������" << pos->m_name << "  ���䣺" << pos->m_age << endl;
	//}
	//else
	//{

	//	cout << "û�ҵ�" << endl;
	//}



	//vector<Person1>::iterator pos = find_if(v1.begin(), v1.end(), Compare_m);
	//if (pos != v1.end())
	//{
	//	cout << "�ҵ��ˣ�������" << pos->m_name << "  ���䣺" << pos->m_age << endl;
	//}
	//else
	//{
	//	cout << "û�ҵ�" << endl;
	//}

	//int it = count_if(v1.begin(), v1.end(), My_count);
	//cout << it;


	//for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;

	//random_shuffle(v.begin(), v.end());

	//for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;

	vector<int>v1;
	vector<int>v2;

	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 6);
	}

	vector<int>v3;
	v3.resize(v1.size() + v2.size());

	cout << "�ϲ�֮��" << endl;

	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}