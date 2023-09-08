#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>

//汉诺塔移动步骤
void hanoi_move(int n, char A, char B, char C)
{
	if (n == 1)
	{
		printf("%c-->%c\t", A, C);
	}
	else 
	{
		hanoi_move(n - 1, A, C, B);
		printf("%c-->%c\t", A, C);
		hanoi_move(n - 1, B, A, C);
	}

}

//汉诺塔移动次数
int hanoi_num(int n)
{

	if (n == 1)
	{
		return 1;
	}
	return 2 * hanoi_num(n - 1) + 1;

}

int main()
{
	int n = 0;
	scanf("%d", &n);
	//hanoi_move(n, '1', '2', '3');
	printf("需要移动%d次\n", hanoi_num(n));

	return 0;
}
