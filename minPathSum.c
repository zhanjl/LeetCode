//此题就是用动态规划来求解
#define M   10
#define N   8
int minPathSum(int grid[M][N])
{
    int temp[N];
    int i, j, row;
    temp[0] = grid[0][0];
    for (i = 1; i < N; i++)
        temp[i] = grid[0][i] + temp[i-1];
    
    row = grid[0][0]; 
    for (i = 1; i < M; i++)
    {
        row += gird[i][0];
        temp[0] = row;
        for (j = 1; j < N; j++)
        {
            if (temp[i-1] < temp[i])
                temp[i] = temp[i-1] + grid[i][j];
            else
                temp[i] = temp[i] + grid[i][j];
        }
    }
    
    return temp[N-1];
}
