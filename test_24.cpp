



//职工管理系统，显示功能、删除功能实现

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

//删除员工副本
void WorkManage::Del_Emp()
{
	if(this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		int id = 0;
		cout << "请输入需要删除的员工编号：" << endl;
		cin >> id;
		int index = this->IsExist(id);
		if (index == -1)
		{
			cout << "删除失败，此员工不存在" << endl;
		}
		else
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->Add_EmpArray[i] = this->Add_EmpArray[i + 1];
			}
			this->m_EmpNum--;

			this->save();
			cout << "删除成功！" << endl;
		}

	}
	system("pause");
}