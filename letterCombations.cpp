void build(string digits, int index, vector<string> &res, string &cur)
{
    if (index == digits.size())
    {
        res.push_back(cur);
        return;
    }
    bool flag = false;
    if (digits[index] == '9' || digits[index] == '7')
        flag = true;

    int offset = 0;
    if (digits[index] >= '8')
        offset = 1;

    char startchar;
    startchar = (digits[index] - '2') * 3 + 'a' + offset;

    for (int i = 0; i < 3; i++)
    {
        cur.push_back(startchar + i);
        build(digits, index+1, res, cur);
        cur.pop_back();
    }

    if (flag)
    {
        cur.push_back(startchar + 3);
        build(digits, index+1, res, cur);
        cur.pop_back();
    }
    return;
}

vector<string> letterCombations(string digits)
{
    vector<string> res;
    string  cur;
    build(digits, 0, res, cur);

    return res;
}
