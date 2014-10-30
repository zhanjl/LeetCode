//该版本空间复杂度太高，可以优化
int uniquePaths(int m, int n)
{
    int path[m][n];
    int i, j;
    for (i = 0; i < n; i++)
        path[0][i] = 1;
    for (i = 0; i < m; i++)
        path[i][0] = 1;

    for (i = 1; i < m; i++)
    {
        for (j = 1; j < n; j++)
            path[i][j] = path[i-1][j] + path[i][j-1];
    }

    return path[m-1][n-1];
}

//空间复杂度较低的版本
int uniquePaths(int m, int n)
{
    int path[2][n];
    int i, j;
    if (m == 1 || n == 1)
        return 1;
    for (i = 0; i < n; i++)
        path[0][i] = 1;
    for (i = 0; i < 2; i++)
        path[i][0] = 1;
    for (j = 1; j < m; j++)
    {
        for (i = 1; i < n; i++)
            path[1][i] = path[1][i-1] + path[0][i];
        for (i = 1; i < n; i++)
            path[0][i] = path[1][i];
    }

    return path[1][n-1];
}

//空间复杂度更低的版本
int uniquePaths(int m, int n)
{
    int path[n];
    int i, j;
    int left, cur;
    for (i = 0; i < n; i++)
        path[i] = 1;
    
    for (i = 1; i < m; i++)
    {
        left = 1;
        for (j = 1; j < n; j++)
        {
            cur = left + path[j];
            left = cur;
            path[j] = cur;
        }
    } 
    return path[n-1];
}
