
#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
#include<list>
using namespace std;



class Person
{

public:
	Person(string name, int score)
	{
		this->m_Name = name;
		this->m_score = score;
	}

	string m_Name;
	int m_score;
};

void CreatePerson(vector<Person>& v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += nameSeed[i];

		int score = 0;

		Person p(name, score);

		v.push_back(p);
	}

}


void SetScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		deque<int> d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;  //分数在60~100之间
			d.push_back(score);
		}

		sort(d.begin(), d.end());

		//去除一个最高分，一个最低分
		d.pop_back();
		d.pop_front();

		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}
		
		(*it).m_score = sum / 8;
	}

}


void Show_Score(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << it->m_Name << "  分数：" << it->m_score << endl;
	}
}



class Person1
{
public:

	Person1(string name, int age, int height)
	{
		this->m_Name = name;
		this->m_Age = age;
		this->m_Height = height;
	}

	string m_Name;
	int m_Age;
	int m_Height;


};

bool ListCompare(Person1& p1, Person1& p2)
{
	if (p1.m_Age == p2.m_Age)
	{
		return p1.m_Height > p2.m_Height;
	}
	else
	{
		return p1.m_Age < p2.m_Age;
	}
}


void show_info(list<Person1>& L)
{
	for (list<Person1>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "姓名：" << it->m_Name << "  年龄：" << it->m_Age << "  身高：" << it->m_Height << endl;
	}
}

void ListSort()
{
	list<Person1>L;
	Person1 p1("张三", 10, 150);
	Person1 p2("李四", 30, 175);
	Person1 p3("王五", 15, 160);
	Person1 p4("赵六", 20, 200);
	Person1 p5("周七", 15, 185);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p1);
	//排序前
	cout << "排序前：" << endl;
	show_info(L);

	
	L.sort(ListCompare);
	cout << "------------------------------------" << endl;
	cout << "排序后：" << endl;
	show_info(L);



}




int main()
{
	//srand((unsigned)time(NULL));
	//vector<Person>v;

	//创建选手
	//CreatePerson(v);

	//测试
	//for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << "姓名：" << it->m_Name << "  分数：" << it->m_score << endl;
	//}

	//10评委打分
	//SetScore(v);

	//显示最终得分
	//Show_Score(v);
	ListSort();


	return 0;
}