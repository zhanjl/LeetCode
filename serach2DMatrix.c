//此问题有两种解法
//方法一，时间复杂度为O(m+n)
//m,n分别为二维矩阵的行和列
#define M   10
#define N   8
bool serachMatrix(int matrix[M][N], int target)
{
    int i, j;
    bool flag;
    i = M - 1;
    j = 0;
    flag = false;

    while (i >= 0 && j < N)
    {
        if (matrix[i][j] == target)
        {
            flag = true;
            break;
        }
        else if (target > matrix[i][j])
            j++;
        else
            i--;
    }
    return flag;
}

//方法二，时间复杂度为O(lgm*n)，其实是利用二分查找
bool serachMatrix(int matrix[M][N], int target)
{
    int low, mid, upper;
    bool flag;
    low = 0;
    upper = M*N - 1;
    flag = false;
    while (low <= upper)
    {
        mid = (low + upper) / 2;

        if (target == matrix[mid/N][mid%N])
        {
            flag = true;
            break;
        }
        else if (target > matrix[mid/N][mid%N])
            low = mid + 1;
        else
            upper = mid - 1;
    }
    return flag;
}
