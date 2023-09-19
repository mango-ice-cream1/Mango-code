

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
	//���ļ�
	ifs.open(FILENAME, ios::in);

	//1���ļ�������
	if (ifs.is_open()==false)
	{
		cout << "�ļ�������" << endl;

		this->m_EmpNum = 0;
		this->Add_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2���ļ�Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ����ڣ���Ϊ�գ�" << endl;

		this->m_EmpNum = 0;
		this->Add_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3���ļ�����
	int num = this->get_EmpNum();
	cout << "Ŀǰ��" << num << "��Ա��" << endl;
	this->m_EmpNum = num;

	//��ʼ��ְ����Ϣ
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


void WorkManage::exitSystem()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}


//���ְ��
void WorkManage::Add_Emp()
{
	int Add_num = 0;
	cout << "���������ְ��������" << endl;
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
			string name = "����";
			int Did = 0;
			cout << "�������" << i + 1 << "��ְ���ı�ţ�" << endl;
			cin >> Id;

			cout << "�������" << i + 1 << "��ְ����������" << endl;
			cin >> name;

			cout << "1.Ա��" << endl
				 << "2.����" << endl
				 << "3.�ϰ�" << endl;
			cout << "��ѡ��ְ����λ��ţ�" << endl;
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

		//���¼�¼�������ʹ�����Ϣ
		this->m_EmpNum = newNum;

		this->Add_EmpArray = newSpace;

		cout << "�ɹ����" << Add_num << "��ְ��" << endl;
		this->m_FileIsEmpty = false;
		save();

	}
	else
	{
		cout << "������������" << endl;
	}

	system("pause");
	system("cls");
	
}

//����ְ����Ϣ
void WorkManage::save()
{
	//�����ļ���
	ofstream ofs;

	//���ļ�
	ofs.open(FILENAME, ios::out);

	//д�ļ�
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->Add_EmpArray[i]->m_ID << " "
			<< this->Add_EmpArray[i]->m_Name << " "
			<< this->Add_EmpArray[i]->m_DeptID << endl;
	}

	//�ر��ļ�
	ofs.close();
}

//��ȡְ��������
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

//ְ����Ϣ��ʼ��
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


//ְ����Ϣ��ʾ
void WorkManage::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ���Ϊ��" << endl;
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

//ְ���Ƿ���ڣ�һ���������������������ڣ����ԶԳ�������޸ģ�
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

//ɾ��ְ��
void WorkManage::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		int id;
		cout << "������Ҫɾ����ְ����ţ�" << endl;
		cin >> id;
		if (this->IsExist(id) == -1)
		{
			cout << "�����ڴ�Ա��" << endl;
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
			cout << "ɾ���ɹ���" << endl;
		}
	}
	system("pause");
}

////ɾ��Ա������
//void WorkManage::Del_Emp()
//{
//	if(this->m_FileIsEmpty)
//	{
//		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
//	}
//	else
//	{
//		int id = 0;
//		cout << "��������Ҫɾ����Ա����ţ�" << endl;
//		cin >> id;
//		int index = this->IsExist(id);
//		if (index == -1)
//		{
//			cout << "ɾ��ʧ�ܣ���Ա��������" << endl;
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
//			cout << "ɾ���ɹ���" << endl;
//		}
//
//	}
//	system("pause");
//}

	//�޸�ְ����Ϣ
void WorkManage::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		cout << "�������޸�ְ����ţ�" << endl;
		int id=0;
		cin >> id;
		int index = this->IsExist(id);
		if (index == -1)
		{
			cout << "�޸�ʧ�ܣ���Ա��������" << endl;
		}
		else
		{
			int newId=0;
			string newName="";
			int newDid=0;
			cout << "���ҵ��˱��Ϊ" << id << "��Ա������������ְ�����:" << endl;
			cin >> newId;
			cout << "��������ְ��������" << endl;
			cin >> newName;
			cout << "��ѡ����ְ��ְλ��" << endl
				 << "1.Ա��" << endl
				 << "2.����" << endl
				 << "3.�ϰ�" << endl;
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

			cout << "�޸ĳɹ�" << endl;
			this->save();
		}
	}

	system("pause");
}

//����ְ����Ϣ
void WorkManage::find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ��߼�¼������" << endl;
	}
	else
	{
		int temp = 0;
		cout << "��ѡ����ҷ�ʽ��" << endl
			 << "1������ְ����Ų���" << endl
			 << "2������ְ����������" << endl;
		cin >> temp;
		if (temp == 1)
		{
			cout << "����������ҵ�ְ����ţ�" << endl;
			int id = 0;
			cin >> id;
			int index = IsExist(id);
			if (index == -1)
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
			else
			{
				cout << "�鵽�ˣ�������Ϣ��" << endl;
				this->Add_EmpArray[index]->ShowInfo();
			}
		}
		else if (temp == 2)
		{
			cout << "��������Ҫ���ҵ�ְ��������" << endl;
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
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else
		{
			cout << "������������:)";
		}

	}
	system("pause");
}

//ְ������
void WorkManage::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		cout << "��ѡ������ʽ" << endl;
		cout << "1������" << endl;
		cout << "2������" << endl;
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

		cout << "����ɹ���" << endl;
		this->save();
		this->Show_Emp();
	}
	system("pause");
	system("cls");
}

//��ղ���
void WorkManage::Clear_File()
{
	cout << "���ٴ�ȷ�ϣ��Ƿ�ɾ����������" << endl
		 << "1��ȷ��" << endl
		 << "2������" << endl;
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
		cout << "����ɹ�" << endl;
	}
	system("pause");
	system("cls");
}