//力扣算法题-验证回文串

#include<ctype.h>
#include<stdio.h>

bool isPalindrome(char* s) {


    int i = 0;
    int t = 0;
    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = tolower(s[i]);
        }
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[t++] = s[i];
        }
    }
    s[t] = '\0';
    int length = 0;
    for (i = 0; s[i] != '\0'; i++)
    {
        length++;
    }

    for (i = 0; i < length / 2; i++)
    {
        if (s[i] != s[length - 1 - i])
        {
            return false;
        }
    }

    return true;
}


int main()
{
    char s[] = "0P";
    printf("%d ",isPalindrome(s));
    return 0;
}


