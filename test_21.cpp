

#include<iostream>
using namespace std;

//�����Ǳ����������⣬û�е�����ɣ�cat��̬û�����

class Animal
{
public:
	virtual void speak()
	{
		cout << "������˵��" << endl;
	}

};

class Cat :public Animal
{
public:
	void spaek()
	{
		cout << "������" << endl;
	}
};
class Dog :public Animal
{
public:
	void speak()
	{
		cout << "������" << endl;
	}
};

void AnimalSpeak(Animal& animal)
{
	animal.speak();
}


void test01()
{
	Cat cat;
	AnimalSpeak(cat);

	Dog dog;
	AnimalSpeak(dog);

	Cat cat2;
	AnimalSpeak(cat2);
}


int main()
{
	test01();
	return 0;
}

