

#include<iostream>
using namespace std;

//可能是编译器的问题，没有调试完成，cat多态没有完成

class Animal
{
public:
	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}

};

class Cat :public Animal
{
public:
	void spaek()
	{
		cout << "喵喵喵" << endl;
	}
};
class Dog :public Animal
{
public:
	void speak()
	{
		cout << "汪汪汪" << endl;
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

