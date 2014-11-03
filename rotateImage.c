//矩阵旋转90度
//1  2  3  4 
//5  6  7  8
//9  10 11 12
//13 14 15 16
//变为
//13 9  5 1
//14 10 6 2
//15 11 7 3
//16 12 8 4
//也就是说第一行变为倒数第一列，第二行变为倒数地二列，以此类推
//
//算法一，要使用额外空间

#define ROW 3
#define COL 4

void rotate(int matrix[ROW][COL])
{
    int tem[COL][ROW];
    int i, j, col;
    col = ROW - 1;
    for (i = 0; i < ROW; i++, col--)
    {
        for (j = 0; j < COL; j++)
            tem[j][col] = matrix[i][j];
    }
    //现在tem存储的就是矩阵旋转90度之后的结果
}

//算法二，不使用额外的空间
//该算法只适用于方阵
//1 2 3
//4 5 6
//7 8 9
//先上下反转
//7 8 9
//4 5 6
//1 2 3
//然后再交换关于对角线对称的元素
//（8,4), (9,1), (6,2)
void rotate(int matrix[4][4])
{
    int i, j, tem
    //上下反转;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 4; j++)
        {
            tem = matrix[3-i][j];
            matrix[3-i][j] = matrix[i][j];
            matrix[i][j] = tem;
        }
    }

    //交换关于对角线对称的元素
    for (i = 0; i < 4; i++)
    {
        for (j = i + 1; j < 4; j++)
        {
            tem = matrix[j][i];
            matrix[j][i] = matrix[i][j];
            matrix[i][j] = tem;
        }
    }
}
