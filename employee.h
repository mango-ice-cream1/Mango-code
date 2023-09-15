#pragma once

#include"worker.h"


class Employee :public worker
{
public:
	//¹¹Ôìº¯Êý
	Employee(int id, string name, int DeptId);
	void ShowInfo();

	string getDeptName();

};
