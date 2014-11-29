//循环递归
void nEleSubset(vector<int> &S, vector<int> &subset, vector<vector<int> > &res, int k, int beg)
{
    if (k == 0)
    {
        if (find(res.begin(), res.end(), subset) == res.end())
            res.push_back(subset);
        return;
    }

    int i;
    for (i = beg; i + k <= S.size(); i++)
    {
        subset.push_back(S[i]);
        nEleSubset(S, subset, res, k - 1, i + 1);
        subset.pop_back();
    }
    return;
}

vector<vector<int> > subset(vector<int> &S)
{
    vector<vector<int> > result;
    vector<int> empty;
    result.push_back(empty);

    int i;
    for (i = 1; i <= S.size(); i++)
    {
        vector<int> subset;
        nEleSubset(S, subset, result, i, 0);
    }

    return result;
}
//C++迭代方法，该解法的思考角度很有意思
//vector<vector<int> > subsets(vector<int> &S)
//{
//  vector<vector<int> > result;
//  vector<int> empty;
//  result.push_back(empty);
//  int i, j;
//  for (i = 0; i < S.size(); i++)
//  {
//     vector<vector<int> > temp = result;
//     for (j = 0; j < result.size(); j++)
//     {
//          result[j].push_back(S[i]);
//          //如果result[j]不在temp中
//          if (find(temp.begin(), temp.end(), result[j]) == temp.end())
//              temp.push_back(result[j]);
//     }
//     result = temp; 
//  }
//
//  return result;
//}
