
bool isValidSudoku(int A[9][9])
{
    int hash[9];
    int i, j;
    int m, n;
    //检查行
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
            hash[j] = 0;
        for (j = 0; j < 9; j++)
        {
            if (A[i][j] != '.')
            {
                if (hash[A[i][j] - '1'] != 0)
                    return false;
                hash[A[i][j] - '1'] = 1;
            }
        }
    }

    //检查列
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
            hash[j] = 0;
        for (j = 0; j < 9; j++)
        {
            if (A[j][i] != '.')
            {
                if (hash[A[j][i] - '1'] != 0)
                    return false;
                hash[A[j][i] - '1'] = 1;
            }
        }
    }

    //检查9个子方格
    for (i = 0; i < 9; i += 3)
    {
        for (j = 0; j < 9; j+= 3)
        {
            for (m = 0; m < 9; m++)
               hash[m] = 0;
            for (m = i; m < i + 3; m++)
            {
                for (n = j; n < j + 3; n++)
                {
                    if (A[m][n] != '.')
                    {
                        if (hash[A[m][n] - '1'] != 0)
                            return false;
                        hash[A[m][n] - '1'] = 1;
                    }
                } 
            } 
        }
    }

    return true;
}


//另一种更简单的方法,采用位图存储标识
bool isValidSudoku(int A[9][9])
{
    int s[9] = {0};
    int r[9] = {0};
    int c[9] = {0};

    int i, j;
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            if (A[i][j] == '.')
                continue;

            int val = A[i][j] - '0';
            int m = 1 << val;

            if (r[i] & m != 0)
                return false;
            if (c[j] & m != 0)
                return false;
            if (s[ 3 * (i / 3) + j / 3] & m != 0)
                return false;
            r[i] |= m;
            c[j] |= m;
            s[ 3 * (i / 3) + j / 3] |= m;
        }
    }

    return true;
}
