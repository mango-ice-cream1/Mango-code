//力扣算法-实现strStr


int strStr(char* haystack, char* needle) {

    int t1, t2, t3;
    for (t1 = 0; haystack[t1] != '\0'; t1++)
    {
        t2 = t1;
        for (t3 = 0; needle[t3] != '\0'; t3++)
        {
            if (haystack[t2] != needle[t3])
            {
                break;
            }
            t2++;
        }
        if (needle[t3] == '\0')
        {
            return t1;
        }
    }

    return -1;
}