
#include<iostream>
using namespace std;


//class Animal
//{
//public:
//	virtual void speak()
//	{
//		cout << "������˵��" << endl;
//	}
//};
//
//
//class Cat: public Animal
//{
//public:
//	 void speak()
//	{
//		cout << "������" << endl;
//	}
//};
//
//class Dog : public Animal
//{
//public:
//	 void speak()
//	{
//		cout << "������" << endl;
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
//	//��ˮ
//	virtual void Boil() = 0;
//
//	//����
//	virtual void Brew() = 0;
//
//	//���뱭��
//	virtual void PourInCup() = 0;
//
//	//��������
//	virtual void PutSomething() = 0;
//
//	//������Ʒ
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
//	//��ˮ
//	virtual void Boil()
//	{
//		cout << "���ũ��ɽȪ" << endl;
//	}
//
//	//����
//	virtual void Brew()
//	{
//		cout << "���뿧��" << endl;
//	}
//
//	//���뱭��
//	virtual void PourInCup()
//	{
//		cout << "���뱭��" << endl;
//	}
//
//	//��������
//	virtual void PutSomething()
//	{
//		cout << "����ţ��" << endl;
//	}
//};
//
//class Tea :public AbstractDrinking
//{
//public:
//	//��ˮ
//	virtual void Boil()
//	{
//		cout << "��ũ��ɽȪ" << endl;
//	}
//
//	//����
//	virtual void Brew()
//	{
//		cout << "�����Ҷ" << endl;
//	}
//
//	//���뱭��
//	virtual void PourInCup()
//	{
//		cout << "���뱭��" << endl;
//	}
//
//	//��������
//	virtual void PutSomething()
//	{
//		cout << "�������" << endl;
//	}
//};
//
//
//
////������Ʒ
//void doWork(AbstractDrinking& drink)
//{
//	drink.MakeDrink();
//}
//
//void test01()
//{
//	cout << "��ʼ�󿧷���" << endl;
//	Coffee coffee;
//	doWork(coffee);
//
//	cout << "-----------------" << endl;
//
//	cout << "��ʼ�ݲ���" << endl;
//	Tea tea;
//	doWork(tea);
//}
//
//int main()
//{
//	test01();
//	return 0;
//}


//˼·������


//�����������CPU,�Կ����ڴ���,�Լ������࣬��Ϊ����

//����CPU
class CPU
{
public:
	//������㺯��
	virtual void calculate() = 0;
};

//�����Կ�
class VideoCard
{
public:
	//������ʾ����
	virtual void display() = 0;
};

//���󴢴濨
class Memory
{
public:
	//���󴢴溯��
	virtual void storage() = 0;
};

class Computer
{
public:
	//computer���캯��
	Computer(CPU* cpu, VideoCard* vc, Memory* mem)
	{
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}

	//���Թ�������
	void Work()
	{
		m_cpu->calculate();

		m_vc->display();

		m_mem->storage();
	}

private:
	CPU* m_cpu;   //CPU
	VideoCard* m_vc;  //�Կ�
	Memory* m_mem;   //���濨
};

//��ʼ����Intel��CPU���Կ������濨

//Intel �� CPU
class IntelCPU :public CPU
{
public:
	virtual void calculate()
	{
		cout << "Intel �� CPU ���ڹ�����" << endl;
	}
};

//Intel �� �Կ�
class IntelVideoCard :public VideoCard
{
	virtual void display()
	{
		cout << "Intel �� �Կ� ���ڹ�����" << endl;
	}
};

//Intel �� ���濨
class IntelMemory :public Memory
{
	virtual void storage()
	{
		cout << "Intel �� ���濨 ���ڹ�����" << endl;
	}
};


//��ʼ����Lenovo��CPU���Կ������濨

//Lenovo �� CPU
class LenovoCPU :public CPU
{
public:
	virtual void calculate()
	{
		cout << "Lenovo �� CPU ���ڹ�����" << endl;
	}
};

//Lenovo �� �Կ�
class LenovoVideoCard :public VideoCard
{
	virtual void display()
	{
		cout << "Lenovo �� �Կ� ���ڹ�����" << endl;
	}
};

//Lenovo �� ���濨
class LenovoMemory :public Memory
{
	virtual void storage()
	{
		cout << "Lenovo �� ���濨 ���ڹ�����" << endl;
	}
};

void test01()
{
	//��һ̨���Ե��������
	CPU* IntelCpu = new IntelCPU;
	VideoCard* IntelCard = new IntelVideoCard;
	Memory* Intelmem = new IntelMemory;

	Computer* computer1 = new Computer(IntelCpu, IntelCard, Intelmem);
	computer1->Work();

	cout << "----------------------------" << endl;

	//�ڶ�̨���Ե��������
	CPU* Lenovo_cpu = new LenovoCPU;
	VideoCard* Lenovo_card = new LenovoVideoCard;
	Memory* Lenovo_mem = new LenovoMemory;
	
	Computer* computer2 = new Computer(Lenovo_cpu, Lenovo_card, Lenovo_mem);
	computer2->Work();

	cout << "----------------------------" << endl;
	//����̨���Ե��������
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