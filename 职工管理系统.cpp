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
		cout << "���������ѡ��" << endl;
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
				cout << "�����������������" << endl;
				system("pause");
				break;
		}
	}

	system("pause");
	system("cls");
	return 0;
}