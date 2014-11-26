//最简单的方法，排序，但是时间复杂度为O(nlgn)
//但是如何才能做到时间复杂度为O(n)
//首先知道不能排序，如果不排序，只能用下面这个思路来求。
//例如序列100 1 3 2 4，读取第一个元素100时，判断99是否
//在集合中，如果在，判断98等等。然后再判断101,102等等（其实往一个方向就找就OK）。
//在判断某个数字是否在集合中时，不能一个个查询，只能用hash。
//使用hash_map来求解。注意hash_map和普通map的区别是速度快，插入和查询都是O(1)的时间
//但缺点是占用空间大。
int longestConsecutive(vector<int> &num)
{
    if (num.size() <= 1)
       return 1;
    unordered_map<int,int> m;
    int i, j, longest, cur;
    
    for (i = 0; i < num.size(); i++)
       m[num[i]] = 1;
    
    longest = 1;
    for (i = 0; i < num.size(); i++)
    {
        cur = 1;
        if (m[num[i]] != 1)
            continue;
        j = num[i] - 1;
        while (m.find(j) != m.end())
        {
            m[j] = 2;
            j--;
            cur++;
        }
        j = num[i] + 1;
        while (m.find(j) != m.end())
        {
            m[j] = 2;
            j++;
            cur++;
        }

        if (cur > longest)
            longest = cur;
    }

    return longest;
}

