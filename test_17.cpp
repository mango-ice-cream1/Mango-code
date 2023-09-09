

#include<iostream>
#include<string>

using namespace std;

#define pi 3.14

class Circle
{
public:
	//属性
	//半径
	int m_r;
	//行为
	double CaculateZC()
	{
		return 2 * pi * m_r;
	}
};


class student
{
public:
	//属性
	string name;
	int std_num;
	//行为
	void Show()
	{
		cout << "姓名：" << name << " " << "学号：" << std_num << endl;
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
	//cout << "圆的周长是：" << r.CaculateZC()<<endl;
	student s1 = { "张三",922303 };
	s1.Set_name("李四");
	s1.Set_std_num(922301);
	s1.Show();
	return 0;
}