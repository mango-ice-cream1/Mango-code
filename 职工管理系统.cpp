#pragma once

#include"WorkManage.h"
#include<iostream>
using namespace std;


int main()
{
	WorkManage ans;
	ans.Show_Menu();

	while (true)
	{
		int choice = 0;
		cout << "请输入你的选择：" << endl;
		cin >> choice;
		switch (choice)
		{
			case 0:
				ans.exitSystem();
				break;
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			default:
				cout << "输入错误，请重新输入" << endl;
				system("pause");
				break;
		}
	}

	system("pause");
	system("cls");
	return 0;
}