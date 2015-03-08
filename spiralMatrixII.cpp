
vector<vector<int> > generateMatrix(int n)
{
    //先定义一个n*n的矩阵
    vector<vector<int> > result;
    for (int i = 0; i < n; i++)
        result.push_back(vector<int>(n));
    
    //把对应数字填入矩阵中
    int k = 1;
    for (int i = 1; i <= n/2; i++) {//总公有n/2-1圈（不算最中间那个元素，如果有的话）
        //每一圈的上面一行(行下标是i-1)，列下标范围是(i-1, n-i)
        for (int j = i - 1; j < n - i; j++)
            result[i-1][j] = k++;
        //每一圈的右面一列(列下标是n-i)，行下标范围是(i-1, n-i)
        for (int j = i - 1; j < n - i; j++)
            result[j][n-i] = k++;
        //每一圈的下面一行(行下标是n-i)，列下标范围是(n-i, i-1)
        for (int j = n - i; j > i - 1; j--)
            result[n-i][j] = k++;
        //每一圈的左面一列(列下标是i-1)，行下标范围是(n-i, i-1)
        for (int j = n - i; j > i - 1; j--)
            result[j][i-1] = k++;
    }

    //如果n是奇数，则最中间还有一个元素
    if (n % 2 == 1) {
        result[n/2][n/2] = k; 
    }

    return result;
}
