//利用二进制位来计算，该方法很精巧
int majorityElement(vector<int> &num)
{
    int cnt0, cnt1;
    int res;
    int i, j;
    res = 0;
    for (i = 31; i >= 0; i--)
    {
        cnt0 = cn1 = 0;
        for (j = 0; j < num.size(); j++)
        {
            if ((num[j] >> i) & 0x1)
                cnt1++;
            else
                cnt0++;
        }
        res = 2 * res;
        if (cnt1 > cnt0)
            res += 1;
    }

    return res;
}
