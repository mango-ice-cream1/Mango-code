
//�����㷨-Atoi����ʵ��


#include<stdio.h>
#include<limits.h>

//ֱ���ж�INT_MIN��INT_MAX��Խ�����
int myAtoi(char* s) {
    int flag = 1;
    int t = 0;
    int final = 0;
    
    if (s[t] == '\0')
    {
        return 0;
    }
    //���ǰ���ַ����ո�
    while (s[t] == ' ')
    {
        t++;
    }
    //�ж�����������
    if (s[t] == '+')
    {
        flag = 1;
        t++;
    }
    else if (s[t] == '-')
    {
        flag = -1;
        t++;
    }
    else
    {
        flag = 1;
    }


    //��ȡ�ַ�����
    while (s[t] >= '0' && s[t] <= '9')
    {
        if (final<=INT_MIN / 10 || final>=INT_MAX / 10)
        {
            if (flag == 1)
            {
                return INT_MAX;
            }
            if (flag == -1)
            {
                return INT_MIN;
            }
        }
        final = final * 10 + flag * (s[t] - '0');
        t++;
    }

    return final;
}

//����double�ж�Խ��
int myAtoi(char* s) {
    int flag = 1;
    int t = 0;
    double final = 0;

    while (s[t] == ' ')t++;
    if (s[t] == '+' || s[t] == '-')
    {
        if (s[t] == '-')
            flag = -1;
        t++;
    }
    while (s[t] >= '0' && s[t] <= '9')
    {
        final = final * 10 + flag * (s[t] - '0');
        if (final<INT_MIN || final>INT_MAX)
        {
            if (final < INT_MIN)
            {
                return INT_MIN;
            }
            else if (final > INT_MAX)
            {
                return INT_MAX;
            }
        }
        t++;
    }
    return final;
}
int main()
{
    char s[] = "-91283472332";
    printf("%d", myAtoi(s));
    return 0;
}