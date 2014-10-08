#include <stdio.h>
#include <stdlib.h>

int numTrees(int n)
{
    int num[n][n];
    int i, j, k;
    if (n == 1)
       return 1;
    for (i = 0; i < n; i++)
       num[i][i] = 1;

    for (k = 1; k < n; k++)
    {
        for (i = 0; i < (n - k); i++)
        {
            //计算num[i][i+k]的值
            num[i][i+k] = num[i+1][i+k] + num[i][i+k-1];
            for (j = i+1; j <= i+k-1; j++)
                num[i][i+k] += num[i][j-1]*num[j+1][i+k];
        }
    }

    return num[0][n-1];
}

//低空间复杂度版本
//利用了一个事实从m...n的数量和从1...n-m的数量一样多
int numTrees1(int n)
{
    int num[n+1];
    int i, j;
    num[1] = 1;
    for (i = 2; i <= n; i++)
    {
        num[i] = 2*num[i-1];
        for (j = 2; j < i; j++)
            num[i] += num[j-1]*num[i-j];
    }
    return num[n];
}
int main()
{
    printf("%d\n", numTrees1(3));
}
