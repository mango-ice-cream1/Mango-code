#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int main()
{
	ָ�붨��ǰ���δ��ָ���ʼ��������Ҫ���ٿռ䣬����ֱ�Ӷ�Ұָ�븳ֵ
	const int n = 10;
	int arr[n] = { 0 };
	char** s = NULL;
	s = (char**)malloc(10 * sizeof(char**));
	char buff[10] = "hello";
	s[0] = (char*)malloc(sizeof(buff));
	strcpy(s[0], buff);
	printf("%s\n", s[0]);
	return 0;
}



