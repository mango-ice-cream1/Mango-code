
#include<iostream>
#include<string>
using namespace std;

class worker
{
public:
	//��ʾ������Ϣ
	virtual void ShowInfo() = 0;

	//��ȡ��λ����
	virtual string getDeptName() = 0;

	int m_ID;
	string m_Name;
	int m_DeptID;

};

class manager :public worker
{
public:
	manager(int id, string name, int Did)
	{
		this->m_ID = id;
		this->m_Name = name;
		this->m_DeptID = Did;
	}
	//��ʾ������Ϣ
	void ShowInfo()
	{
		cout << "ְ����ţ�" << this->m_ID << "\t"
			<< "ְ��������" << this->m_Name << "\t"
			<< "ְ����λ��" << this->getDeptName() << "\t"
			<< "����ϰ��������񣬸�Ա����������" << endl;
	}
	//��ȡ��λ����
	string getDeptName()
	{
		return string("����");
	}

	int m_ID;
	string m_Name;
	int m_DeptID;

};

void test01()
{
	manager p1(1, "����", 1);
	cout << "p1.m_ID=" << p1.m_ID << endl;
	cout << "p1.Name=" << p1.m_Name << endl;
	cout << "p1.m_DeptID=" << p1.m_DeptID << endl;
}
void test02()
{
	worker* p2 = new manager(1, "����", 1);
	cout << "p2->m_ID=" << p2->m_ID << endl;
	cout << "p2->Name=" << p2->m_Name << endl;
	cout << "p2->m_DeptID=" << p2->m_DeptID << endl;
}

int main()
{
	cout << "test01()���ý����" << endl;
	test01();

	cout << "test02()���ý����" << endl;
	test02();

	return 0;
}







