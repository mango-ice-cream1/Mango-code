
//力扣算法-Atoi函数实现


#include<stdio.h>
#include<limits.h>

//直接判断INT_MIN和INT_MAX的越界情况
int myAtoi(char* s) {
    int flag = 1;
    int t = 0;
    int final = 0;
    
    if (s[t] == '\0')
    {
        return 0;
    }
    //清除前导字符（空格）
    while (s[t] == ' ')
    {
        t++;
    }
    //判断有无正负号
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


    //读取字符数字
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

//创建double判断越界
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