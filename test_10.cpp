#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int main()
{
	指针定义前如果未对指针初始化，则需要开辟空间，不能直接对野指针赋值
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



