#pragma once

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