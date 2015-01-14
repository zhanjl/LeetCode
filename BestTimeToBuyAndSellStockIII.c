//算法一，分别求出prices[0..i]和prices[i+1,,size-1]（i从0到size-1)
//的最大值，然后求和。求和结果最大的一个即为最终结果
//时间复杂度是O(n^2)
int intervalMax(vector<int> &prices, int beg, int end)
{
    int min, res;
    res = 0;
    min = prices[beg];
    for (int i = beg + 1; i <= end; i++)
    {
        if (prices[i] > min)
        {
            if (prices[i] - min > res)
                res = prices[i] - min;
        }
        else
        {
            min = prices[i];
        }
    }

    return res;
}

int maxProfit(vector<int> &prices)
{
    int len, res, max1, max2;
    len = prices.size();
    if (len <= 1)
        return 0;
    res = 0;
    for (int i = 1; i < len; i++)
    {
        max1 = intervalMax(prices, 0, i);
        max2 = intervalMax(prices, i + 1, len - 1);
        if (max1 + max2 > res)
            res = max1 + max2;
    }

    return res;
}

//使用动态规划，已知prices[0..i]的最大值，可以在
//O(1)时间内求出prices[0...i+1]的最大值。
//时间复杂度为O(n)
int maxProfit(vector<int> &prices)
{
    int len, min, max;
    int res;
    len = prices.size();
    if (len <= 1)
        return 0;
    int l[len], r[len];
    l[0] = 0;
    min = prices[0];
    for (int i = 1; i < len; i++)
    {
        if (prices[i] - min > l[i-1])
            l[i] = prices[i] - min;
        else
            l[i] = l[i-1];

        if (prices[i] < min)
            min = prices[i];
    }

    r[len-1] = 0;
    max = prices[len-1];
    for (int i = len - 2; i >= 0; i--)
    {
        if (max - prices[i] > r[i+1])
            r[i] = max - prices[i];
        else
            r[i] = r[i+1];

        if (prices[i] > max)
            max = prices[i];
    }

    res = 0;
    for (int i = 0; i < len; i++)
    {
        if (l[i] + r[i] > res)
            res = l[i] + r[i];
    }

    return res;
}
