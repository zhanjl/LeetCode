//通过这一题可以学到一个解决问题的思维方式
//碰到一个复杂问题不知道如何入手时，可以先
//从简单的特例着手解决，一般可以找到一个思路
//
//算法一：利用递归来做，但时间复杂度太高
//加上剪枝，运行时间能降低很多
//判断s1的beg1到end1和s2的beg2到end2是否是scramble
bool compare(string &s1, string &s2, int beg1, int end1, int beg2, int end2)
{
    if (beg1 == end1)   //此时beg2 == end2
    {
        if (s1[beg1] == s2[beg2])
            return true;
        return false;
    }
    //剪枝，两个字符串的ascii值必须相等
    int sum1, sum2;
    sum1 = sum2 = 0;
    for (int i = 0; i <= end1 - beg1; i++)
    {
        sum1 += s1[beg1 + i];
        sum2 += s2[beg2 + i];
    }
    if (sum1 != sum2)
        return false;

    //i是分割点
    for (int i = beg1; i < end1; i++)
    {
        if (compare(s1, s2, beg1, i, beg2, beg2 + i - beg1))
        {
            if (compare(s1, s2, i + 1, end1, end2 - (end1 - i - 1), end2))
                return true;
        }
         
        if (compare(s1, s2, beg1, i, end2 - (i - beg1), end2))
        {
            if (compare(s1, s2, i + 1, end1, beg2, beg2 + (end1 - i - 1)))
                return true;
        }
    }
    return false;
}

//s1和s2的长度一样
bool isScramble(string s1, string s2)
{
    if (s1.size() == 0)
        return true;
    return compare(s1, s2, 0, s1.size() - 1, 0, s2.size() - 1); 
}

//算法二：使用动态规划
//result[k][i][j]表示s1从i开始s2从j开始长度
//为k的字符串是否是scramble
bool isScramble(string s1, string s2)
{
    int len, i, j, k, divid;
    len = s1.size();

    bool result[len+1][len+1][len+1];

    //初始化
    for (i = 1; i <= len; i++)
    {
        for (j = 1; j <= len; j++)
        {
            if (s1[i-1] == s2[j-1])
                result[1][i][j] = true;
            else
                result[1][i][j] = false;
        }
    }

    for (k = 2; k <= len; k++)
    {
        for (i = 1; i <= len - k + 1; i++)
        {
            for (j = 1; j <= len - k + 1; j++)
            {
                //计算result[k][i][j]
                for (divid = 1; divid < k; divid++)
                {
                    if (result[divid][i][j] && result[k-divid][i+divid][j+divid])
                    {
                        result[k][i][j] = true;
                        break;
                    }

                    if (result[divid][i][j+k-divid] && result[k-divid][i+divid][j])
                    {
                        result[k][i][j] = true;
                        break;
                    }
                }

                if (divid == k)
                    result[k][i][j] = false;
            }
        }
    }
    return result[len][1][1];
}
