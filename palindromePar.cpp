//判断一个字符串是否是回文串
bool isPalindrome(string s, int beg, int end)
{
    while (beg <= end)
    {
        if (s[beg] != s[end])
            return false;
        beg++;
        end--;
    }
    return true;
}

void realwork(vector<vector<string> > &res, vector<string> &cur,
            string s, int beg, int end)
{
    if (beg > end)
    {
        res.push_back(cur);
        return;
    }
    int i;
    for (i = beg; i <= end; i++)
    {
        if (!isPalindrome(s, beg, i))
            continue;
        string pal(s, beg, i - beg + 1);
        cur.push_back(pal);
        realwork(res, cur, s, i + 1, end);
        cur.pop_back();
    }
    return;
}

vector<vector<string> > partition(string s)
{
    vector<vector<string> > result; 
    vector<string> cur;
    if (s.size() == 0)
        return result;
    realwork(result, cur, s, 0, s.size() - 1);
    return result;
}
