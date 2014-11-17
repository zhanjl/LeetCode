//循环递归
void generate(int n, int k, int beg, vector<int> item, vector<vector<int> > &res)
{
    if (k == 0)
    {
        res.push_back(item);
        return;
    }
    int i;
    for (i = beg; i <= n+1-k; i++)
    {
        item.push_back(i);
        generate(n, k-1, i+1, item, res);
        item.pop_back();
    }
}

vector<vector<int> > combine(int n, int k)
{
    vector<vector<int> > result;
    vector<int> item;
    generate(n, k, 1, item, result);
    return result;
}
