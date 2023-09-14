
#include<iostream>
using namespace std;


//class Animal
//{
//public:
//	virtual void speak()
//	{
//		cout << "动物在说话" << endl;
//	}
//};
//
//
//class Cat: public Animal
//{
//public:
//	 void speak()
//	{
//		cout << "喵喵喵" << endl;
//	}
//};
//
//class Dog : public Animal
//{
//public:
//	 void speak()
//	{
//		cout << "汪汪汪" << endl;
//	}
//};
//
//void doSpeak(Animal& animal)
//{
//	animal.speak();
//}
//
//void test01()
//{
//	Cat cat;
//	doSpeak(cat);
//
//	Dog dog;
//	doSpeak(dog);
//}
//
//int main()
//{
//	test01();
//	return 0;
//}


//class AbstractDrinking
//{
//public:
//
//	//煮水
//	virtual void Boil() = 0;
//
//	//冲泡
//	virtual void Brew() = 0;
//
//	//倒入杯中
//	virtual void PourInCup() = 0;
//
//	//加入佐料
//	virtual void PutSomething() = 0;
//
//	//制作饮品
//	void MakeDrink()
//	{
//		Boil();
//		Brew();
//		PourInCup();
//		PutSomething();
//	}
//};
//
//
//class Coffee :public AbstractDrinking
//{
//public:
//	//煮水
//	virtual void Boil()
//	{
//		cout << "煮沸农夫山泉" << endl;
//	}
//
//	//冲泡
//	virtual void Brew()
//	{
//		cout << "加入咖啡" << endl;
//	}
//
//	//倒入杯中
//	virtual void PourInCup()
//	{
//		cout << "倒入杯中" << endl;
//	}
//
//	//加入佐料
//	virtual void PutSomething()
//	{
//		cout << "加入牛奶" << endl;
//	}
//};
//
//class Tea :public AbstractDrinking
//{
//public:
//	//煮水
//	virtual void Boil()
//	{
//		cout << "煮农夫山泉" << endl;
//	}
//
//	//冲泡
//	virtual void Brew()
//	{
//		cout << "加入茶叶" << endl;
//	}
//
//	//倒入杯中
//	virtual void PourInCup()
//	{
//		cout << "倒入杯中" << endl;
//	}
//
//	//加入佐料
//	virtual void PutSomething()
//	{
//		cout << "加入枸杞" << endl;
//	}
//};
//
//
//
////制作饮品
//void doWork(AbstractDrinking& drink)
//{
//	drink.MakeDrink();
//}
//
//void test01()
//{
//	cout << "开始煮咖啡啦" << endl;
//	Coffee coffee;
//	doWork(coffee);
//
//	cout << "-----------------" << endl;
//
//	cout << "开始泡茶啦" << endl;
//	Tea tea;
//	doWork(tea);
//}
//
//int main()
//{
//	test01();
//	return 0;
//}


//思路先理清


//创建基本零件CPU,显卡，内存条,以及电脑类，作为基类

//抽象CPU
class CPU
{
public:
	//抽象计算函数
	virtual void calculate() = 0;
};

//抽象显卡
class VideoCard
{
public:
	//抽象显示函数
	virtual void display() = 0;
};

//抽象储存卡
class Memory
{
public:
	//抽象储存函数
	virtual void storage() = 0;
};

class Computer
{
public:
	//computer构造函数
	Computer(CPU* cpu, VideoCard* vc, Memory* mem)
	{
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}

	//电脑工作函数
	void Work()
	{
		m_cpu->calculate();

		m_vc->display();

		m_mem->storage();
	}

private:
	CPU* m_cpu;   //CPU
	VideoCard* m_vc;  //显卡
	Memory* m_mem;   //储存卡
};

//开始构造Intel的CPU，显卡，储存卡

//Intel 的 CPU
class IntelCPU :public CPU
{
public:
	virtual void calculate()
	{
		cout << "Intel 的 CPU 正在工作！" << endl;
	}
};

//Intel 的 显卡
class IntelVideoCard :public VideoCard
{
	virtual void display()
	{
		cout << "Intel 的 显卡 正在工作！" << endl;
	}
};

//Intel 的 储存卡
class IntelMemory :public Memory
{
	virtual void storage()
	{
		cout << "Intel 的 储存卡 正在工作！" << endl;
	}
};


//开始构造Lenovo的CPU，显卡，储存卡

//Lenovo 的 CPU
class LenovoCPU :public CPU
{
public:
	virtual void calculate()
	{
		cout << "Lenovo 的 CPU 正在工作！" << endl;
	}
};

//Lenovo 的 显卡
class LenovoVideoCard :public VideoCard
{
	virtual void display()
	{
		cout << "Lenovo 的 显卡 正在工作！" << endl;
	}
};

//Lenovo 的 储存卡
class LenovoMemory :public Memory
{
	virtual void storage()
	{
		cout << "Lenovo 的 储存卡 正在工作！" << endl;
	}
};

void test01()
{
	//第一台电脑的三个零件
	CPU* IntelCpu = new IntelCPU;
	VideoCard* IntelCard = new IntelVideoCard;
	Memory* Intelmem = new IntelMemory;

	Computer* computer1 = new Computer(IntelCpu, IntelCard, Intelmem);
	computer1->Work();

	cout << "----------------------------" << endl;

	//第二台电脑的三个零件
	CPU* Lenovo_cpu = new LenovoCPU;
	VideoCard* Lenovo_card = new LenovoVideoCard;
	Memory* Lenovo_mem = new LenovoMemory;
	
	Computer* computer2 = new Computer(Lenovo_cpu, Lenovo_card, Lenovo_mem);
	computer2->Work();

	cout << "----------------------------" << endl;
	//第三台电脑的三个零件
	CPU* Intel_cpu = new IntelCPU;
	VideoCard* Lenovo_card2 = new LenovoVideoCard;
	Memory* Lenovo_mem2 = new LenovoMemory;

	Computer* computer3 = new Computer(Intel_cpu, Lenovo_card2, Lenovo_mem2);
	computer3->Work();

}

int main()
{
	test01();
	return 0;
}