
#pragma once
#include"WorkManage.h"
#include<iostream>
using namespace std;

WorkManage::WorkManage()
{

}

WorkManage::~WorkManage()
{

}


void WorkManage::Show_Menu()
{
	cout << "***************************************" << endl;
	cout << "******** ��ӭʹ��ְ������ϵͳ! ********" << endl;
	cout << "************ 0.�˳�������� ***********" << endl;
	cout << "************ 1.����ְ����Ϣ ***********" << endl;
	cout << "************ 2.��ʾְ����Ϣ ***********" << endl;
	cout << "************ 3.ɾ����ְְ�� ***********" << endl;
	cout << "************ 4.�޸�ְ����Ϣ ***********" << endl;
	cout << "************ 5.����ְ����Ϣ ***********" << endl;
	cout << "************ 6.���ձ������ ***********" << endl;
	cout << "************ 7.��������ĵ� ***********" << endl;
	cout << "***************************************" << endl;
}


void exitSystem()
{
	exit(0);
}

