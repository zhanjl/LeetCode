#define M   3
#define N   4
//算法一，需要O(M+N)空间复杂度
void setZeros(int data[M][N])
{
    int flag[M+N];
    int i, j;
    for (i = 0; i < M + N; i++)
        flag[i] = 0;
    //标记，如果第i行需要赋值为0，则令flag[i] = 1
    //如果第i列需要赋值为0,则令flag[M+i] = 1
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (data[i][j] == 0)
             {
                 flag[i] = 1;
                 flag[M+j] = 1;
             }
        }
    }
    //把行赋值为0
    for (i = 0; i < M; i++)
    {
        if (flag[i] == 1)
        {
            for (j = 0; j < N; j++)
                data[i][j] = 0;
        }
    }
    //把列赋值为0
    for (i = 0; i < N; i++)
    {
        if (flag[i+M] == 1)
        {
            for (j = 0; j < M; j++)
                data[j][i] = 0;
        }
    }
}
//算法二：
//上述算法的时间复杂度可以降为O(max(M, N))，没必要
//分配这么大的标记空间，可以只分配O(max(M, N))大小的空间
//标记有四个值0, 1, 2, 3。1代表该行需要置为0, 2代表列需要置为0,
//3代表行和列都需要置为0
void setZeros(int data[M][N])
{
    int max;
    max = ( M > N) ? M : N;
    int flag[max];
    int i, j;
    
    for (i = 0; i < max; i++)
        flag[i] = 0;

    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (data[i][j] == 0)
            {
                //标记行 
                if (flag[i] == 0 || flag[i] == 2)
                    flag[i]++;
                //标记列 
                if (flag[j] == 0)
                    flag[j] = 2;
                //标记行和列
                else if (flag[j] == 1)
                    flag[j] = 3;
            }
        }
    }

    for (i = 0; i < max; i++)
    {
        //操作行
        if (flag[i] == 1)
        {
            for (j = 0; j < N; j++)
                data[i][j] = 0;
        }
        //操作列
        else if (flag[i] == 2)
        {
            for (j = 0; j < M; j++)
                data[j][i] = 0;
        }
        //操作行和列
        else if (flag[i] == 3)
        {
            for (j = 0; j < N; j++)
                data[i][j] = 0;
            for (j = 0; j < M; j++)
                data[j][i] = 0;
        }
    }
}

//算法三，空间复杂度为O(1)，
//其实这种想法最巧妙，本质上和算法一完全一样，只不过用第一行和
//第一列存储标志，然后用额外的两个变量来标识第一行和第一列是否
//应该置为0，标志为0，说明应该置为0,这一点和算法一不一样！！
void setZeros(int data[M][N])
{
    int row, column;
    int i, j;
    row = column = 1;
    
    for (i = 0;i < N; i++)
    {
        if (data[0][i] == 0)
        {
            row = 0;
            break;
        }
    }

    for (i = 0; i < M; i++)
    {
        if (data[i][0] == 0)
        {
            column = 0;
            break;
        }
    }
     
    for (i = 1; i < M; i++)
    {
        for (j = 1; j < N; j++)
        {
            if (data[i][j] == 0)
            {
                data[i][0] = 0;
                data[0][j] = 0;
            }
        }
    } 

    for (i = 1; i < M; i++)
    {
        for (j = 1; j < N; j++)
        {
            if (data[i][0] == 0 || data[0][j] == 0)
                data[i][j] = 0;
        }
    }

    if (row == 0)
    {
        for (i = 0; i < N; i++)
           data[0][i] = 0; 
    }

    if (column == 0)
    {
        for (i = 0; i < M; i++)
            data[i][0] = 0;
    }
}
