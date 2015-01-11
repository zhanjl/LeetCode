//使用动态规划
//假设当前字符串长度为k+1，总共的方案数是f(k+1)
//则f(k+1) = f(k) + f(k-1)，如果第k和k+1的字符是有效的组合
//否则f(k+1) = f(k)

int numDecodings(string s)
{
    vector<int> temp;
    if (s.size() == 0)
        return 0;
    temp.push_back(1);
    if (s[0] == '0')
        temp.push_back(0);
    else
        temp.push_back(1);
    if (s.size() == 1)
        return temp[1];
    int i, size, num, code;
    size = s.size();
    for (i = 2; i <= size; i++)
    {
        //如果s[1..i-1]不是有效编码，那么再增加字符也组不成有效编码
        if (temp[i-1] == 0)
            return 0;
        if (s[i-1] == '0')
            num = 0;
        else
            num = temp[i-1];
        code = (s[i-2] - '0') * 10 + s[i-1] - '0';
        if (code <= 26 && code >= 10)   //01--09不是有效编码
            num += temp[i-2];
        temp.push_back(num);
    }
    return temp[size];
}
