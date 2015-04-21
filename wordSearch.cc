
bool DFS(vector<vector<char> > &board, int i, int j, vector<vector<char> > &flag, string word, int cur)
{
    int f = 0;
    if (cur == word.size())
        return true;

    if (board[i][j] != word[cur])
        return false;
    //此时board[i][j] == wrod[cur]
    //得考虑一种特殊情况，无路可走应该返回true 
    if ((i - 1) >= 0 && flag[i-1][j] == 0) {
        f = 1;
        flag[i-1][j] = 1;
        if (DFS(board, i - 1, j, flag, word, cur + 1)) {
            return true;   
        }
        flag[i-1][j] = 0;
    }

    if (((j + 1) < board[0].size()) && flag[i][j+1] == 0) {
        f = 1;
        flag[i][j+1] = 1;
        if (DFS(board, i, j + 1, flag, word, cur + 1))
            return true;
        flag[i][j+1] = 0;
    }

    if ((i + 1 < board.size()) && flag[i+1][j] == 0) {
        f = 1;
        flag[i+1][j] = 1;
        if (DFS(board, i + 1, j, flag, word, cur + 1))
            return true;
        flag[i+1][j] = 0;
    }

    if (((j - 1) >= 0) && flag[i][j-1] == 0) {
        f = 1;
        flag[i][j-1] = 1;
        if (DFS(board, i, j - 1, flag, word, cur + 1))
            return true;
        flag[i][j-1] = 0;
    }
    if (f == 0 && cur == word.size() - 1)
       return true; 
    return false;
}

bool exist(vector<vector<char> > &board, string word)
{
    if (board.size() == 0)
        return false;
    vector<char>  temp;
    vector<vector<char> > flag;
    for (int i = 0; i < board[0].size(); i++)
        temp.push_back(0);
    for (int i = 0; i < board.size(); i++)
        flag.push_back(temp);

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] != word[0])
                continue;
            flag[i][j] = 1;
            if (DFS(board, i, j, flag, word, 0))
                return true;
            flag[i][j] = 0;
        }
    }

    return false;
}
