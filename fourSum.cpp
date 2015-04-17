//循环递归方法
void generate(vector<vector<int> > &res, vector<int> &num, vector<int> &cur, int beg, int target, int len)
{
    if (len == 1) {
        for (int i = beg; i < num.size(); i++) {
            if (num[i] == target) {
                cur.push_back(num[i]);
                vector<int> temp = cur;
                sort(temp.begin(), temp.end());
                if (find(res.begin(), res.end(), temp) == res.end())
                    res.push_back(temp);
                return;
            }
        }
    } else {
        for (int i = beg; i < num.size(); i++) {
            cur.push_back(num[i]);
            generate(res, num, cur, i + 1, target - num[i], len - 1);
            cur.pop_back();
        }
    }
    return;
}

vector<vector<int> > fourSum(vector<int> &num, int target) 
{ 
    vector<vector<int> > res;
    if (num.size() < 4)
        return res;
     
    vector<int> cur;
    generate(res, num, cur, 0, target, 4);  
     
    return res;
}


//转化为在已排序的数组中寻找两个数字之和为target的问题
vector<vector<int> > fourSum(vector<int> &num, int target) 
{
    vector<vector<int> > res;
    if (num.size() < 4)
        return res;
    
    vector<int> cur;
    sort(num.begin(), num.end());
     
    for (int i = 0; i < num.size(); i++) {
        cur.push_back(num[i]);
        target = target - num[i];
        for (int j = i + 1; j < num.size(); j++) {
            cur.push_back(num[j]);
            target = target - num[j];

            int beg, end;
            beg = j + 1;
            end = num.size() - 1;

            while (beg < end) {
                if ((num[beg] + num[end]) == target) {
                    cur.push_back(num[beg]);
                    cur.push_back(num[end]);
                    if (find(res.begin(), res.end(), cur) == res.end())
                        res.push_back(cur);
                    cur.pop_back();
                    cur.pop_back();

                    beg++;
                    end--;
                } else if ((num[beg] + num[end]) < target) {
                    beg++;
                } else {
                    end--;
                }
            }
            cur.pop_back();
            target = target + num[j];
        }
        cur.pop_back();
        target = target + num[i];
    }

    return res;
}
