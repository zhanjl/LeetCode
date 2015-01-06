//使用桶排序
int findmax(vector<int> &num)
{
    int ret = num[0];
    for (vector<int>::size_type i = 1; i < num.size(); i++)
    {
        if (num[i] > ret)
            ret = num[i];
    }
    return ret;
}
int findmin(vector<int> &num)
{
    int ret = num[0];
    for (vector<int>::size_type i = 1; i < num.size(); i++)
    {
        if (num[i] < ret)
            ret = num[i];
    }
    return ret;
}

int maximumGap(vector<int> &num)
{
    if (num.size() < 2)
        return 0;
    int min, max, len, size;
   // int ret;
    min = findmin(num);
    max = findmax(num);
    len = (max - min) / (num.size() - 1);   //每个桶的大小，len有可能为0
    if (len == 0)
        len = 1;
    size = (max-min)/len + 1;               //桶的个数
    vector<vector<int> > bucket(size);
    //把元素放入到对应的桶中
    for (vector<int>::size_type i = 0; i < num.size(); i++)
        bucket[(num[i] - min)/len].push_back(num[i]);
    

    //最大差距肯定是min(bucket[i+1]) - max(bucket[i])   bucket[i] bucket[i+1]不为空
    int ret = 0;
    max = findmax(bucket[0]);
    for (vector<int>::size_type i = 1; i < bucket.size(); i++)
    {
        if (bucket[i].size() == 0)
            continue;
        min = findmin(bucket[i]);
        if ((min - max) > ret)
            ret = min - max;
        max = findmax(bucket[i]);
    }
    return ret;
}
