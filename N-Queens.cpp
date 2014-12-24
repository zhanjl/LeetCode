//把棋盘上(row,col)处皇后能攻击到的所有棋盘格的值都加上val，val的值为1或-1
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

string generatestr(int pos, int size)
{
    string str;
    int i;
    for (i = 0; i < size; i++)
        str.push_back('.');
    str[pos] = 'Q';

    return str;
}

void printchess(vector<vector<int> > &chess)
{
    int i, j;
    for (i = 0; i < chess.size(); i++)
    {
        for (j = 0; j < chess.size(); j++)
            cout << chess[i][j] << " ";
        cout << endl;
    }
}
void buildsolute(vector<vector<string> > &result, vector<vector<int> > &chess,
        vector<string> &solution, int row)
{
    if (row == chess.size())
    {
        result.push_back(solution);
        return;
    }

    for (int i = 0; i < chess[row].size(); i++)
    {
        if (chess[row][i] == 0)
        {
            solution.push_back(generatestr(i, chess[row].size()));
            setattack(chess, row, i, 1);
            buildsolute(result, chess, solution, row + 1);
            solution.pop_back();
            setattack(chess, row, i, -1);
        }
    }
}
vector<vector<string> > solveNQueens(int n)
{
    vector<vector<string> > result;
    vector<vector<int> >    chess;
    vector<string>  solution;
    //初始化棋盘 
    vector<int>     row(n, 0);
    for (int i = 0; i < n; i++)
        chess.push_back(row);

    buildsolute(result, chess, solution, 0);

    return result;
}

