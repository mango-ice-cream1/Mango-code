#pragma once

#include"worker.h"


class Employee :public worker
{
public:
	//���캯��
	Employee(int id, string name, int DeptId);
	void ShowInfo();

	string getDeptName();

};
