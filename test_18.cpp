

#include<stdio.h>

#include<iostream>

using namespace std;

//���1000���ڵ�ˮ�ɻ���
//void SXH_num1()
//{
//    for (int i = 1; i < 10; i++)
//    {
//        for (int j = 0; j < 10; j++)
//        {
//            for (int k = 0; k < 10; k++)
//            {
//                if (i * 100 + j * 10 + k == i * i * i + j * j * j + k * k * k)
//                {
//                    cout << i * 100 + j * 10 + k << " ";
//                }
//            }
//        }
//    }
//}
//
////�ж��Ƿ���ˮ�ɻ���
//void SXH_num2()
//{
//    int num = 0;
//    cout << "������һ��1000���ڵ����֣�" << endl;
//    cin >> num;
//    int a = num / 100;
//    int temp = num % 100;
//    int b = temp / 10;
//    int c = temp % 10;
//    if (a * a * a + b * b * b + c * c * c == num)
//    {
//        cout << num << "��ˮ�ɻ���\n";
//    }
//    else
//    {
//        cout << num << "����ˮ�ɻ���\n";
//    }
//}
//
//
//void hanoi_move(int n, int A, int B, int C)
//{
//    if (1 == n)
//    {
//        printf("%d-->%d\t", A, C);
//    }
//    else
//    {
//        hanoi_move(n - 1, A, C, B);//��n-1��Բ�̴�A�ƶ���B
//        printf("%d-->%d\t", A, C);//����n��Բ�̴�A���ƶ���C��
//        hanoi_move(n - 1, B, A, C);//��n-1��Բ�̴�B���ƶ���C��
//    }
//}



//ˮ�ɻ���
//int main()
//{
//    int n = 10;
//    hanoi_move(n, 'A', 'B', 'C');
//    //ˮ�ɻ���
//    //SXH_num1();
//    //SXH_num2();
//    return 0;
//}

//int main() {
//    int h = 10;
//    char flag = 'y';
//    while (tolower(flag) != 'n') {
//        cout << "��ŵ������" << endl << "Please input the number of the diskes: ";
//        cin >> h;
//        cout << "The steps to moving " << h << " diskes are as follows:" << endl;
//        hanoi_move(h, 1, 2, 3);
//        cout << endl << "Do you want to go on?(y for yes, n for no) ";
//        cin >> flag;
//    }
//    return 0;
//}


//�˻ʺ�����
//int main()
//{
//	int count = 0;//������
//	for (int q1 = 0; q1 < 8; q1++)
//	{
//		for (int q2 = 0; q2 < 8; q2++)
//		{
//			if (q1 == q2 || q1 == q2 + 1 || q1 == q2 - 1)
//			{
//				continue;
//			}
//			for (int q3 = 0; q3 < 8; q3++)
//			{
//				if (q1 == q3 || q1 == q3 + 2 || q1 == q3 - 2
//					|| q2 == q3 || q2 == q3 + 1 || q2 == q3 - 1)
//				{
//					continue;
//				}
//				for (int q4 = 0; q4 < 8; q4++)
//				{
//					if (q1 == q4 || q1 == q4 + 3 || q1 == q4 - 3
//						|| q2 == q4 || q2 == q4 + 2 || q2 == q4 - 2
//						|| q3 == q4 || q3 == q4 + 1 || q3 == q4 - 1)
//					{
//						continue;
//					}
//					for (int q5 = 0; q5 < 8; q5++)
//					{
//						if (q1 == q5 || q1 == q5 + 4 || q1 == q5 - 4
//							|| q2 == q5 || q2 == q5 + 3 || q2 == q5 - 3
//							|| q3 == q5 || q3 == q5 + 2 || q3 == q5 - 2
//							|| q4 == q5 || q4 == q5 + 1 || q4 == q5 - 1)
//						{
//							continue;
//						}
//						for (int q6 = 0; q6 < 8; q6++)
//						{
//							if (q1 == q6 || q1 == q6 + 5 || q1 == q6 - 5
//								|| q2 == q6 || q2 == q6 + 4 || q2 == q6 - 4
//								|| q3 == q6 || q3 == q6 + 3 || q3 == q6 - 3
//								|| q4 == q6 || q4 == q6 + 2 || q4 == q6 - 2
//								|| q5 == q6 || q5 == q6 + 1 || q5 == q6 - 1)
//							{
//								continue;
//							}
//							for (int q7 = 0; q7 < 8; q7++)
//							{
//								if (q1 == q7 || q1 == q7 + 6 || q1 == q7 - 6
//									|| q2 == q7 || q2 == q7 + 5 || q2 == q7 - 5
//									|| q3 == q7 || q3 == q7 + 4 || q3 == q7 - 4
//									|| q4 == q7 || q4 == q7 + 3 || q4 == q7 - 3
//									|| q5 == q7 || q5 == q7 + 2 || q5 == q7 - 2
//									|| q6 == q7 || q6 == q7 + 1 || q6 == q7 - 1)
//								{
//									continue;
//								}
//								for (int q8 = 0; q8 < 8; q8++)
//								{
//									if (q1 == q8 || q1 == q8 + 7 || q1 == q8 - 7
//										|| q2 == q8 || q2 == q8 + 6 || q2 == q8 - 6
//										|| q3 == q8 || q3 == q8 + 5 || q3 == q8 - 5
//										|| q4 == q8 || q4 == q8 + 4 || q4 == q8 - 4
//										|| q5 == q8 || q5 == q8 + 3 || q5 == q8 - 3
//										|| q6 == q8 || q6 == q8 + 2 || q6 == q8 - 2
//										|| q7 == q8 || q7 == q8 + 1 || q7 == q8 - 1)
//									{
//										continue;
//									}
//									count++;
//									printf("%d,%d,%d,%d,%d,%d,%d,%d\n", q1, q2, q3, q4, q5, q6, q7, q8);
//								}
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//	printf("һ����%d�ַ���", count);
//	return 0;
//}





//���õ���
class point
{
public:
	//����x
	void setX(int x)
	{
		m_x = x;
	}
	//��ȡx
	int getX()
	{
		return m_x;
	}
	//����y
	void setY(int y)
	{
		m_y = y;
	}
	//��ȡy
	int getY()
	{
		return m_y;
	}
private:
	int m_x;
	int m_y;
};

class Circle
{
public:
	//���ð뾶
	void setR(int r)
	{
		m_r = r;
	}
	//��ȡ�뾶
	int getR()
	{
		return m_r;
	}
	//����Բ��
	void setCenter(point center)
	{
		m_center = center;
	}
	//��ȡԲ��
	point getCenter()
	{
		return m_center;
	}
private:
	int m_r;
	point m_center;
};

void Caculate_S(Circle& s, point& p)
{
	int distance = (s.getCenter().getX() - p.getX()) * (s.getCenter().getX() - p.getX()) +
		(s.getCenter().getY() - p.getY()) * (s.getCenter().getY() - p.getY());
	int r_distance = s.getR() * s.getR();
	if (distance == r_distance)
	{
		cout << "����Բ��" << endl;
	}
	else if (distance > r_distance)
	{
		cout << "����Բ��" << endl;
	}
	else
	{
		cout << "����Բ��" << endl;
	}
}


int main()
{
	Circle r1{};
	
	return 0;
}

