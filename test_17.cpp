

#include<iostream>
#include<string>

using namespace std;

#define pi 3.14

class Circle
{
public:
	//����
	//�뾶
	int m_r;
	//��Ϊ
	double CaculateZC()
	{
		return 2 * pi * m_r;
	}
};


class student
{
public:
	//����
	string name;
	int std_num;
	//��Ϊ
	void Show()
	{
		cout << "������" << name << " " << "ѧ�ţ�" << std_num << endl;
	}
	void Set_name(string temp)
	{
		name = temp;
	}
	void Set_std_num(int id)
	{
		std_num = id;
	}

};


int main()
{
	//Circle r = { 10 };
	//cout << "Բ���ܳ��ǣ�" << r.CaculateZC()<<endl;
	student s1 = { "����",922303 };
	s1.Set_name("����");
	s1.Set_std_num(922301);
	s1.Show();
	return 0;
}