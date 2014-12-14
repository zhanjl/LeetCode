//深度优先搜索
void generate(vector<vector<int> > &res, vector<int> &cand, int beg, 
            int end, int sum, vector<int> &cur, int target)
{
    int i;
    for (i = beg; i <= end; i++)
    {
        cur.push_back(cand[i]);
        sum += cand[i];
        if (sum == target)
        {
            res.push_back(cur);
            cur.pop_back();
            return;
        }
        else if (sum > target)
        {
            cur.pop_back();
            return;
        }
        generate(res, cand, i, end, sum, cur);
        cur.pop_back();
        sum -= cand[i];
    }
    return;
}

vector<vector<int> > combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int> > res;
    vector<int> cur;
    sort(candidates.begin(), candidates.end());
    generate(res, candidates, 0, candidates.size() - 1, 0, cur, target);
    return res; 
}
