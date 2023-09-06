

#include<iostream>

using namespace std;



#define MAX 100
typedef struct
{
    int data;
    char key;
}Data_type;

typedef struct
{
    Data_type A[MAX + 1];
    int length;
}SqList;




//冒泡排序

SqList BubbleSort(SqList L)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < L.length - 1; i++)//走length-1趟
    {
        for (j = 0; j < L.length - 1 - i; j++)//比较length-1-i次(i=0,1,2...length-2)
        {
            if (L.A[j].data > L.A[j + 1].data)
            {
                Data_type temp = L.A[j + 1];
                L.A[j + 1] = L.A[j];
                L.A[j] = temp;
            }
        }
    }
    return L;
}

void Show_List(SqList L)
{
    for (int i = 0; i < L.length; i++)
    {
        cout << L.A[i].data << " ";
    }
}

int main()
{
    SqList L = { 0 };
    L.length = 10;
    for (int i = 0; i < L.length; i++)
    {
        L.A[i].data = L.length - i;
    }
    cout << "排序前：";
    Show_List(L);
    cout << endl;
    L = BubbleSort(L);
    cout << "排序后：";
    Show_List(L);
    return 0;
}