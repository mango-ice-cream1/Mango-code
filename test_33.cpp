

#include<string>
#include<iostream>
using namespace std;


class Course
{
public:

	Course()
	{

	}

	Course(string tempcno, string tempcname) :cno(tempcno), cname(tempcname) {}

	Course(const Course& c)
	{
		this->cno = c.cno;
		this->cname = c.cname;
	}

	void course_show()
	{
		cout << "�γ̺ţ�" << this->cno << endl
			 << "�γ�����" << this->cname << endl;
	}

	//int cno;
	string cno;
	string cname;
};

class Score
{
public:

	Score()
	{

	}
	Score(int temps):score(temps){}

	Score(Score& tempss) :score(tempss.score) {}



	void score_show()
	{
		cout << "������" << this->score << endl;
	}

	int score;
};

class Student
{
public:

	Student()
	{
		
	}
	Student(int tempsno, string tempsname, string tempgender, string tempgrade, Course tempsc, Score tempss):
		sno(tempsno), sname(tempsname), gender(tempgender), grade(tempgrade), scourse(tempsc), sscore(tempss) {}

	

	void student_show()
	{
		cout << "ѧ�ţ�" << this->sno << endl
			<< "������" << this->sname << endl
			<< "�Ա�" << this->gender << endl
			<< "�༶��" << this->grade << endl;
		scourse.course_show();
		sscore.score_show();
	}

private:
	int sno;
	string sname;
	string gender;
	string grade;
	Course scourse;
	Score sscore;
};

//int main() {
//	Course cs1(19218120, "C++");	Score sc1(90);
//	Student st1(201811219, "����", "��", "�ƿ�161", cs1, sc1);
//	st1.student_show();
//	
//	return 0;
//}


#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;
const int cnumber = 2;

int main() {
	Student  st[cnumber];	Course  cs[cnumber];	Score  ss[cnumber];
	char flag = 'Y';
	while (toupper(flag) == 'Y') {
		cout << "������" << cnumber << "���γ̼��������Ϣ�����磺2016116101 ���� �� �ƿ�161 COST3114 C++ 90��:" << endl;
		int i, msno, mscore;	string msname, mgender, mgrade, mcno, mcname;
		for (i = 0; i < cnumber; i++) {
			cin >> msno >> msname >> mgender >> mgrade >> mcno >> mcname >> mscore;
			Course tcs(mcno, mcname);		cs[i] = tcs;
			Score tss(mscore);		ss[i] = tss;
			Student tst(msno, msname, mgender, mgrade, tcs, tss);		st[i] = tst;
		}
		cout << "ѧ���γ̳ɼ���Ϣ����:" << endl;
		for (i = 0; i < cnumber; i++) { st[i].student_show(); }
		cout << "----------------------------------------------------------------------" << endl;
		cout << "��������γ̳ɼ���?(Y/N)";
		cin >> flag;
	}
	return 0;
}
