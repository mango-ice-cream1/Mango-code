
#include<iostream>
#include<string>
using namespace std;

class worker
{
public:
	//显示个人信息
	virtual void ShowInfo() = 0;

	//获取岗位名称
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
	//显示个人信息
	void ShowInfo()
	{
		cout << "职工编号：" << this->m_ID << "\t"
			<< "职工姓名：" << this->m_Name << "\t"
			<< "职工岗位：" << this->getDeptName() << "\t"
			<< "完成老板分配的任务，给员工分配任务" << endl;
	}
	//获取岗位名称
	string getDeptName()
	{
		return string("经理");
	}

	int m_ID;
	string m_Name;
	int m_DeptID;

};

void test01()
{
	manager p1(1, "张三", 1);
	cout << "p1.m_ID=" << p1.m_ID << endl;
	cout << "p1.Name=" << p1.m_Name << endl;
	cout << "p1.m_DeptID=" << p1.m_DeptID << endl;
}
void test02()
{
	worker* p2 = new manager(1, "张三", 1);
	cout << "p2->m_ID=" << p2->m_ID << endl;
	cout << "p2->Name=" << p2->m_Name << endl;
	cout << "p2->m_DeptID=" << p2->m_DeptID << endl;
}

int main()
{
	cout << "test01()调用结果：" << endl;
	test01();

	cout << "test02()调用结果：" << endl;
	test02();

	return 0;
}







