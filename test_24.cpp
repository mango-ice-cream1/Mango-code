



//ְ������ϵͳ����ʾ���ܡ�ɾ������ʵ��

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

//ɾ��Ա������
void WorkManage::Del_Emp()
{
	if(this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		int id = 0;
		cout << "��������Ҫɾ����Ա����ţ�" << endl;
		cin >> id;
		int index = this->IsExist(id);
		if (index == -1)
		{
			cout << "ɾ��ʧ�ܣ���Ա��������" << endl;
		}
		else
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->Add_EmpArray[i] = this->Add_EmpArray[i + 1];
			}
			this->m_EmpNum--;

			this->save();
			cout << "ɾ���ɹ���" << endl;
		}

	}
	system("pause");
}