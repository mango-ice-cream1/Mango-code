

#include"WorkManage.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<iostream>
using namespace std;
#include<string>

#include<fstream>
#define FILENAME "empFILE.txt"


WorkManage::WorkManage()
{
	
	
	ifstream ifs;
	//打开文件
	ifs.open(FILENAME, ios::in);

	//1、文件不存在
	if (ifs.is_open()==false)
	{
		cout << "文件不存在" << endl;

		this->m_EmpNum = 0;
		this->Add_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2、文件为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件存在，但为空！" << endl;

		this->m_EmpNum = 0;
		this->Add_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3、文件存在
	int num = this->get_EmpNum();
	cout << "目前有" << num << "名员工" << endl;
	this->m_EmpNum = num;

	//初始化职工信息
	this->Add_EmpArray = new worker * [this->m_EmpNum];
	this->InitEmp();

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << this->Add_EmpArray[i]->m_ID << " "
			<< this->Add_EmpArray[i]->m_Name << " "
			<< this->Add_EmpArray[i]->m_DeptID << " " << endl;
	}

}

WorkManage::~WorkManage()
{
	if (Add_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (Add_EmpArray[i] != NULL)
			{
				delete Add_EmpArray[i];
			}
		}
		delete[]Add_EmpArray;
		Add_EmpArray = NULL;
	}
}


void WorkManage::Show_Menu()
{
	cout << "***************************************" << endl;
	cout << "******** 欢迎使用职工管理系统! ********" << endl;
	cout << "************ 0.退出管理程序 ***********" << endl;
	cout << "************ 1.增加职工信息 ***********" << endl;
	cout << "************ 2.显示职工信息 ***********" << endl;
	cout << "************ 3.删除离职职工 ***********" << endl;
	cout << "************ 4.修改职工信息 ***********" << endl;
	cout << "************ 5.查找职工信息 ***********" << endl;
	cout << "************ 6.按照编号排序 ***********" << endl;
	cout << "************ 7.清空所有文档 ***********" << endl;
	cout << "***************************************" << endl;
}


void WorkManage::exitSystem()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}


//添加职工
void WorkManage::Add_Emp()
{
	int Add_num = 0;
	cout << "请输入添加职工人数：" << endl;
	cin >> Add_num;

	if (Add_num > 0)
	{
		int newNum = this->m_EmpNum + Add_num;
		worker** newSpace = new worker * [newNum];

		if (this->Add_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->Add_EmpArray[i];
			}
		}

		for (int i = 0; i < Add_num; i++)
		{
			int Id = 0;
			string name = "张三";
			int Did = 0;
			cout << "请输入第" << i + 1 << "个职工的编号：" << endl;
			cin >> Id;

			cout << "请输入第" << i + 1 << "个职工的姓名：" << endl;
			cin >> name;

			cout << "1.员工" << endl
				 << "2.经理" << endl
				 << "3.老板" << endl;
			cout << "请选择职工岗位编号：" << endl;
			cin >> Did;
			worker* Worker = NULL;
			switch (Did)
			{
			case 1:
				Worker = new employee(Id, name, 1);
				break;
			case 2:
				Worker = new manager(Id, name, 2);
				break;
			case 3:
				Worker = new boss(Id, name, 3);
				break;
			default:
				break;
			}
			newSpace[this->m_EmpNum + i] = Worker;
		}

		//更新记录，人数和储存信息
		this->m_EmpNum = newNum;

		this->Add_EmpArray = newSpace;

		cout << "成功添加" << Add_num << "名职工" << endl;
		this->m_FileIsEmpty = false;
		save();

	}
	else
	{
		cout << "输入数据有误" << endl;
	}

	system("pause");
	system("cls");
	
}

//保存职工信息
void WorkManage::save()
{
	//创建文件类
	ofstream ofs;

	//打开文件
	ofs.open(FILENAME, ios::out);

	//写文件
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->Add_EmpArray[i]->m_ID << " "
			<< this->Add_EmpArray[i]->m_Name << " "
			<< this->Add_EmpArray[i]->m_DeptID << endl;
	}

	//关闭文件
	ofs.close();
}

//获取职工的人数
int WorkManage::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;
	}

	//ifs.close();
	return num;
}

//职工信息初始化
void WorkManage::InitEmp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	int id=1;
	string name="mm";
	int Did=1;

	int index=0;
	while (ifs >> id && ifs >> name && ifs >> Did)
	{
		worker* wm = NULL;
		if (Did == 1)
		{
			wm = new employee(id, name, Did);
		}
		else if (Did == 2)
		{
			wm = new manager(id, name, Did);
		}
		else
		{
			wm = new boss(id, name, Did);
		}
		this->Add_EmpArray[index] = wm;
		index++;
	}
	
	ifs.close();
}


//职工信息显示
void WorkManage::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->Add_EmpArray[i]->ShowInfo();
		}
	}
	system("pause");
	system("cls");

}

//职工是否存在（一个函数不建议有两个出口，所以对程序进行修改）
int  WorkManage::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->Add_EmpArray[i]->m_ID == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

//删除职工
void WorkManage::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		int id;
		cout << "请输入要删除的职工编号：" << endl;
		cin >> id;
		if (this->IsExist(id) == -1)
		{
			cout << "不存在此员工" << endl;
		}
		else
		{
			int newSize = this->m_EmpNum - 1;
			worker** newSpace = new worker * [newSize];

			for (int i = id - 1; i < this->m_EmpNum - 1; i++)
			{
				this->Add_EmpArray[i] = this->Add_EmpArray[i + 1];
			}

			for (int i = 0; i < newSize; i++)
			{
				newSpace[i] = this->Add_EmpArray[i];
			}

			delete[]this->Add_EmpArray;

			this->Add_EmpArray = newSpace;
			this->m_EmpNum = newSize;
			this->save();
			cout << "删除成功！" << endl;
		}
	}
	system("pause");
}

////删除员工副本
//void WorkManage::Del_Emp()
//{
//	if(this->m_FileIsEmpty)
//	{
//		cout << "文件不存在或者记录为空" << endl;
//	}
//	else
//	{
//		int id = 0;
//		cout << "请输入需要删除的员工编号：" << endl;
//		cin >> id;
//		int index = this->IsExist(id);
//		if (index == -1)
//		{
//			cout << "删除失败，此员工不存在" << endl;
//		}
//		else
//		{
//			for (int i = index; i < this->m_EmpNum - 1; i++)
//			{
//				this->Add_EmpArray[i] = this->Add_EmpArray[i + 1];
//			}
//			this->m_EmpNum--;
//
//			this->save();
//			cout << "删除成功！" << endl;
//		}
//
//	}
//	system("pause");
//}

	//修改职工信息
void WorkManage::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		cout << "请输入修改职工编号：" << endl;
		int id=0;
		cin >> id;
		int index = this->IsExist(id);
		if (index == -1)
		{
			cout << "修改失败，该员工不存在" << endl;
		}
		else
		{
			int newId=0;
			string newName="";
			int newDid=0;
			cout << "查找到了编号为" << id << "的员工，请输入新职工编号:" << endl;
			cin >> newId;
			cout << "请输入新职工姓名：" << endl;
			cin >> newName;
			cout << "请选择新职工职位：" << endl
				 << "1.员工" << endl
				 << "2.经理" << endl
				 << "3.老板" << endl;
			cin >> newDid;
			worker* newEmp = NULL;
			switch (newDid)
			{
				case 1:
					newEmp = new employee(newId, newName, 1);
					break;
				case 2:
					newEmp = new manager(newId, newName, 2);
					break;
				case 3:
					newEmp = new boss(newId, newName, 3);
					break;
				default:
					break;
			}
			delete this->Add_EmpArray[index];
			this->Add_EmpArray[index] = newEmp;

			cout << "修改成功" << endl;
			this->save();
		}
	}

	system("pause");
}

//查找职工信息
void WorkManage::find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件为空或者记录不存在" << endl;
	}
	else
	{
		int temp = 0;
		cout << "请选择查找方式：" << endl
			 << "1、按照职工编号查找" << endl
			 << "2、按照职工姓名查找" << endl;
		cin >> temp;
		if (temp == 1)
		{
			cout << "请输入需查找的职工编号：" << endl;
			int id = 0;
			cin >> id;
			int index = IsExist(id);
			if (index == -1)
			{
				cout << "查找失败，查无此人" << endl;
			}
			else
			{
				cout << "查到了，此人信息：" << endl;
				this->Add_EmpArray[index]->ShowInfo();
			}
		}
		else if (temp == 2)
		{
			cout << "请输入需要查找的职工姓名：" << endl;
			string TName = "";			
			bool flag = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->Add_EmpArray[i]->m_Name == TName)
				{
					flag = true;
					this->Add_EmpArray[i]->ShowInfo();
				}
			}
			if (flag == false)
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else
		{
			cout << "输入数据有误:)";
		}

	}
	system("pause");
}

//职工排序
void WorkManage::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		cout << "请选择排序方式" << endl;
		cout << "1、升序" << endl;
		cout << "2、降序" << endl;
		int choice=0;
		cin >> choice;

		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int MinOrMax = i;
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				//
				if (choice == 1)
				{
					if (this->Add_EmpArray[i]->m_ID > this->Add_EmpArray[j]->m_ID)
					{
						MinOrMax = j;
					}
				}
				else
				{
					if (this->Add_EmpArray[i]->m_ID < this->Add_EmpArray[j]->m_ID)
					{
						MinOrMax = j;
					}
				}

				if (i != MinOrMax)
				{
					worker* temp = this->Add_EmpArray[i];
					this->Add_EmpArray[i] = this->Add_EmpArray[MinOrMax];
					this->Add_EmpArray[MinOrMax] = temp;
				}
			}
		}

		cout << "排序成功！" << endl;
		this->save();
		this->Show_Emp();
	}
	system("pause");
	system("cls");
}

//清空操作
void WorkManage::Clear_File()
{
	cout << "请再次确认，是否删除？？！！" << endl
		 << "1、确认" << endl
		 << "2、返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->Add_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->Add_EmpArray[i] != NULL)
				{
					delete this->Add_EmpArray[i];
				}
			}
			delete[] this->Add_EmpArray;

			this->Add_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
			
		}
		cout << "清除成功" << endl;
	}
	system("pause");
	system("cls");
}