#pragma once

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