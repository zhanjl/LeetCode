void setattack(vector<vector<int> > &chess, int row, int col, int val)
{
    int i, j;
    int col1, col2;
    //设置所在行的值
    for (j = 0; j < chess[row].size(); j++)
        chess[row][j] += val;
    //设置所在列的值
    for (i = 0; i < chess.size(); i++)
        chess[i][col] += val;
    //设置两条对角线的值
    col1 = col2 = col;
    for (i = row; i >= 0; i--)
    {
        if (col1 >= 0)
            chess[i][col1] += val;
        if (col2 < chess[row].size())
            chess[i][col2] += val;
        col1--;
        col2++;
    }
    col1 = col2 = col;
    for (i = row; i < chess.size(); i++)
    {
        if (col1 >= 0)
            chess[i][col1] += val;
        if (col2 < chess[row].size())
            chess[i][col2] += val;
        col1--;
        col2++;
    }
}

void buildsolute(vector<vector<int> > &chess, int row, int *res)
{
    if (row == chess.size())
    {
        (*res)++;
        return;
    }

    for (int i = 0; i < chess[row].size(); i++)
    {
        if (chess[row][i] == 0)
        {
            setattack(chess, row, i, 1);
            buildsolute(chess, row + 1, res);
            setattack(chess, row, i, -1);
        }
    }
}

int totalNQueens(int n)
{
    vector<vector<int> >    chess;
    //初始化棋盘 
    vector<int>     row(n, 0);
    int result = 0;
    for (int i = 0; i < n; i++)
        chess.push_back(row);

    buildsolute(chess, 0, &result);
    return result;
}

