
int lengthOfLongestSubstring(string s)
{
    int res, curlen;
    int i, j, start;
    if (s.size() <= 1)
        return s.size();
    res = 0;
    curlen = 1;
    start = 0;
    for (i = 1; i < s.size(); i++)
    {
        for (j = start; j < i; j++)
        {
            if (s[j] == s[i])
                break;
        }
        
        if (j != i)
        {
            start = j + 1;
            if (curlen > res)
                res = curlen;
            curlen = i - j;
        }
        else
        {
            curlen++;
        }
    }
    
    if (curlen > res)
        res = curlen;
    return res;
}
