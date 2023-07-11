

//力扣有效数独


bool isValidSudoku(char** board, int boardSize, int* boardColSize) {

    int i, j, k;
    int row = boardSize / (*boardColSize);
    int col = *boardColSize;
    int* arr = (int*)malloc(col * sizeof(int));



    //遍历行
    for (i = 0; i < row; i++)
    {
        for (k = 0; k < col; k++)
            arr[k] = 0;//初始化检测数组

        for (j = 0; j < col; j++)
        {
            if (board[i][j] != '.')
            {
                arr[board[i][j] - '0' - 1]++;
            }
        }

        for (k = 0; k < col; k++)
        {
            if (arr[k] >= 2)
            {
                return false;
            }
        }
    }

    //遍历列
    for (j = 0; j < col; j++)
    {
        for (k = 0; k < col; k++)
            arr[k] = 0;

        for (i = 0; i < row; i++)
        {
            if (board[i][j] != '.')
            {
                arr[board[i][j] - '0' - 1]++;
            }
        }
        for (k = 0; k < col; k++)
        {
            if (arr[k] >= 2)
            {
                return false;
            }
        }
    }
    //宫遍历
    int count = 0;
    int n = 0;
    for (k = 0; k < col; k++)
    {
        int t1 = (k / 3) * 3;
        int t2 = (k % 3) * 3;
        if (count % 3 == 0)
        {
            int t = 0;
            for (t = 0; t < col; t++)
            {
                arr[t] = 0;
            }
        }
        for (i = 0; i < row / 3; i++)
        {
            for (j = 0; j < col / 3; j++)
            {
                if (board[i + t1][j + t2] != '.')
                {
                    arr[board[i + t1][j + t2] - '0' - 1]++;
                }
            }
            count++;
        }
        for (n = 0; n < col; n++)
        {
            if (arr[n] >= 2)
            {
                return false;
            }
        }

    }


    return true;
}