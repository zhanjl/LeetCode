//这是一道经典的DP问题（还是没有掌握解决动态规划问题的思路）
//dp[i][j]表示T的前j个字符在S的前i个字符中出现的次数
//那么有如下递推公式：
//dp[i][j] = dp[i-1][j]，S[i] != T[j]
//dp[i][j] = dp[i-1][j] + dp[i-1][j-1]，S[i] == T[j]
int numDistinc(string S, string T)
{
    int len1, len2;
    len1 = S.size();
    len2 = T.size();
    
    if (len1 < len2)
       return 0;
    int dp[len2+1];
    int i, j;
    for (i = 0; i <= len2; i++)
        dp[i] = 0;
    dp[0] = 1;
    int cur,prev;   //用于保存dp[i-1][j-1]的值
    for (i = 1; i <= len1; i++)
    {
        prev = dp[0];
        for (j = 1; j <= len2; j++)
        {
            cur = dp[j];    //dp[i-1][j]的值
            if (S[i-1] == T[j-1])
            {
                dp[j] += prev;
            }
            prev = cur;
        }
    }
    return dp[len2];
}
