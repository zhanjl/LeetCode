//时间复杂度是O(n^2)，利用了2Sum的算法
//但是要注意去除重复的结果
vector<vector<int> > threeSum(vector<int> &num)
{
    vector<int> tem(num);
    vector<vector<int> > result;
    if (tem.size() < 3)
        return result;
    sort(tem.begin(), tem.end());
    int first, second, three;
    for (first = 0; first <= tem.size() - 3; first++) {
        if (first != 0 && tem[first] == tem[first-1])                       //去除重复
            continue;
        second = first + 1;
        three = tem.size() - 1; 

        while (second < three) {
            if (second != (first + 1) && tem[second] == tem[second-1]) {    //去除重复
                second++;
                continue;
            }
            if ((tem[second] + tem[three]) == -tem[first]) {
                vector<int> cur;
                cur.push_back(tem[first]);
                cur.push_back(tem[second]);
                cur.push_back(tem[three]);
                result.push_back(cur);
                second++;
                continue;
            }

            else if ((tem[second] + tem[three]) < -tem[first])
                second++;
            else if ((tem[second] + tem[three]) > -tem[first])
                three--;
        }

    }

    return result;
}

