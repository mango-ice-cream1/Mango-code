//力扣算法题，最长公共前缀


char* longestCommonPrefix(char** strs, int strsSize) {

    char* s = (char*)malloc(200 * sizeof(char));
    s = strs[0];
    int i = 0;
    int j = 0;
    int count = 0;
    while (i < strsSize)
    {
        count = 0;
        for (j = 0; s[j] != '\0' && strs[i][j] != '\0'; j++)
        {
            if (s[j] == strs[i][j])
            {
                count++;
            }
            else
            {
                break;
            }
        }
        s[count] = '\0';
        i++;
    }
    if (count == 0)
    {
        return;
    }
    else
    {
        return s;
    }

}