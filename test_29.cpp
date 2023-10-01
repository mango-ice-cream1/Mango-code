//
//#include"MyArray.hpp"
//#include"class.hpp"
//#include<string>
//using namespace std;
//
//
//
////类模板的分文件编写
//
////void test01()
////{
////	Person<string, int>p1("Mark", 10);
////	p1.Show_info();
////}
//
//template<class T1, class T2>
//class My_class;
//
////可以清晰的观察到，以下Show_info2函数是个函数模板
//template<class T1, class T2>
//void Show_info2(My_class<T1, T2> p)
//{
//	cout << "p.m_t1 = " << p.m_t1 << "  p.m_t2 = " << p.m_t2 << endl;
//}
//
////类模板与友元
////全局函数的类内实现和类外实现
//
//template<class T1,class T2>
//class My_class
//{
//	//友元全局函数的类内实现
//	friend void Show_info(My_class<T1, T2> p)
//	{
//		cout << "p.m_t1 = " << p.m_t1 << "  p.m_t2 = " << p.m_t2 << endl;
//	}
//
//	//友元全局函数的类外实现
//	//friend void Show_info2(My_class<T1, T2> p);//可以观察到，此Show_info2函数是普通函数，无法链接到其类外实现
//	//只需要将其变成模板函数即可，添加空模板参数列表<>
//	friend void Show_info2<>(My_class<T1, T2> p);
//
//public:
//
//	My_class(T1 t1,T2 t2)
//	{
//		this->m_t1 = t1;
//		this->m_t2 = t2;
//	}
//
//	T1 m_t1;
//	T2 m_t2;
//
//};
//
//
//
//
////void test02()
////{
////	My_class<int, int> p2(10, 10);
////	Show_info(p2);
////}
////
////void test03()
////{
////	My_class<int, int> p3(10, 20);
////	Show_info2(p3);
////}
//
//void test01()
//{
//	MyArray<int> arr1(5);
//	MyArray<int> arr2(arr1);
//	MyArray<int> arr3(100);
//	arr3 = arr1;
//}
//
//
//void Show_array(MyArray<int> arr)
//{
//	for (int i = 0; i < arr.getSize(); i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//}
//void test02()
//{
//	MyArray<int> arr1(5);
//	for (int i = 0; i < arr1.getCapacity(); i++)
//	{
//		arr1.Push_Back(i+1);
//	}
//	Show_array(arr1);
//	arr1.Pop_Back();
//	Show_array(arr1);
//	cout << arr1.getSize() << endl;
//	
//}
//
//int main()
//{
//	//test01();
//	//test02();
//	//test03();
//	//test01();
//	test02();
//	return 0;
//}
//
//


#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>




//vector容器

void test01()
{

}


class Person
{
public:

	Person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}

	string m_name;
	int m_age;

};
void Print(Person*& p)
{
	cout << "姓名： " << p->m_name << "  年龄： " << p->m_age << endl;
}

int main()
{
	//vector<int> v;
	//v.push_back(10);
	//v.push_back(20);
	//v.push_back(30);
	//v.push_back(40);

	//vector<int>::iterator it_begin = v.begin();
	//vector<int>::iterator it_end   = v.end();
	//while (it_begin != it_end)
	//{
	//	cout << *it_begin << " ";
	//	it_begin++;
	//}

	//for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << *it << " ";
	//}
	
	//for_each(v.begin(), v.end(), Print);
	//vector<Person*> v;
	//Person p1("aaa", 10);
	//Person p2("bbb", 20);
	//Person p3("ccc", 30);
	//Person p4("ddd", 40);
	//Person p5("eee", 50);

	//v.push_back(&p1);
	//v.push_back(&p2);
	//v.push_back(&p3);
	//v.push_back(&p4);
	//v.push_back(&p5);

	//for_each(v.begin(), v.end(), Print);

	//vector容器嵌套

	vector<vector<int>> v;

	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;

	for (int i = 0; i < 4; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}

	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	
	//由此可知，迭代器创建的对象才是指针，但就容器不是指针不能解引用，比如*v就是错误操作，但是由迭代器类型创建的对象it就是一个指针
	//可以通过解引用找到容器中对应元素，迭代器的使用还是应该要注意，嵌套的时候，注意分辨迭代器和容器，迭代器是访问容器的接口

	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		for (vector<int>::iterator m_it = (*it).begin(); m_it != (*it).end(); m_it++)
		{
			cout << *m_it << " ";
		}
		cout << endl;
	}

	return 0;
}

