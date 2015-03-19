//使用循环递归
void combination(vector<int> &num, int target, vector<vector<int> > &res, 
                    vector<int> &cur, int beg)
{
    if (target == 0) {      //找到一个解决方案，方案存放在cur中
        vector<int> temp(cur);
        sort(temp.begin(), temp.end());   //排序
        if (find(res.begin(), res.end(), temp) == res.end()) {
            res.push_back(temp);
        }
        return;
    } else if (target < 0) {
        return;
    }
    //target大于0的情况
    for (int i = beg; i < num.size(); i++) {
        cur.push_back(num[i]);
        combination(num, target - num[i], res, cur, i + 1);
        cur.pop_back();
    }
    return;
}

vector<vector<int> > combinationSum2(vector<int> &num, int target)
{
    vector<vector<int> >    result;
    vector<int>             cur;
    combination(num, target, result, cur, 0);
    return result;
}

