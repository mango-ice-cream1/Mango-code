



#include<iostream>

using namespace std;

void SXH_num1()
{
    for (int i = 1; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                if (i * 100 + j * 10 + k == i * i * i + j * j * j + k * k * k)
                {
                    cout << i * 100 + j * 10 + k << " ";
                }
            }
        }
    }
}

void SXH_num2()
{
    int num = 0;
    cout << "������һ��1000���ڵ����֣�" << endl;
    cin >> num;
    int a = num / 100;
    int temp = num % 100;
    int b = temp / 10;
    int c = temp % 10;
    if (a * a * a + b * b * b + c * c * c == num)
    {
        cout << num << "��ˮ�ɻ���\n";
    }
    else
    {
        cout << num << "����ˮ�ɻ���\n";
    }
}

#include<stdio.h>
void hanoi_move(int n, int A, int B, int C)
{
    if (1 == n)
    {
        printf("%d-->%d\t", A, C);
    }
    else
    {
        hanoi_move(n - 1, A, C, B);//��n-1��Բ�̴�A�ƶ���B
        printf("%d-->%d\t", A, C);//����n��Բ�̴�A���ƶ���C��
        hanoi_move(n - 1, B, A, C);//��n-1��Բ�̴�B���ƶ���C��
    }
}



//ʵ��γ���
//int main()
//{
//    int n = 10;
//    hanoi_move(n, 'A', 'B', 'C');
//    //ˮ�ɻ���
//    //SXH_num1();
//    //SXH_num2();
//    return 0;
//}

int main() {
    int h=10;
    char flag='y';
    while (tolower(flag) != 'n') {
        cout << "��ŵ������" << endl << "Please input the number of the diskes: ";
        cin >> h;
        cout << "The steps to moving " << h << " diskes are as follows:" << endl;
        hanoi_move(h, 1, 2, 3);
        cout << endl << "Do you want to go on?(y for yes, n for no) ";
        cin >> flag;
    }
    return 0;
}
