//编辑距离问题，关键是这个解题思路这个看待问题的方式很有意思
//例如，要把word1[0...i]变为word2[0...j]，有三种方法
//1,把word1[0...i-1]变为word2[0...j-1]，然后把word1[i]替换为word2[j]
//2,把word1[0...i-1]变为word2[0...j]，然后删除word1[i]
//3,把word1[0...i]变为word2[0...j-1]，然后插入word1[i]
//取1,2,3中的最小值即为结果
//最简单的方法是递归，但是速度太慢，这时动态规划派上用场了
int min3(int a, int b, int c)
{
    if (a < b)
        return a < c ? a : c;
    else
        return b < c ? b : c;
}

int minDistance(string word1, string word2)
{
    int len1, len2;
    int i, j;
    int rep;
    len1 = word1.size();
    len2 = word2.size();
    int cost[len1+1][len2+1];
    //注意cost[i][j]表示word1的前i个字符和word2的前j个字符
    //对应的下标为word1[0...i-1]，也就是说word1[0]对应cost[1][j]。
    cost[0][0] = 0;  //word1的前0个字符和word2的前0个字符
    for (i = 1; i <= len1; i++)
        cost[i][0] = i;     //word1删除i个字符

    for (j = 1; j <= len2; j++)
        cost[0][j] = j;     //word2删除j个字符

    for (i = 1; i <= len1; i++)
    {
        for (j = 1; j <= len2; j++)
        {
            rep = 0;
            if (word1[i-1] != word2[j-1])
                rep = 1;    //需要替换     替换         插入        删除
            cost[i][j] = min3(cost[i-1][j-1]+rep, cost[i-1][j]+1, cost[i][j-1]+1);
        }
    }

    return cost[len1][len2];
}

//降低空间复杂度的版本
int minDistance(string word1, string word2)
{
    int len1, len2;
    len1 = word1.size();
    len2 = word2.size();

    int prev[len1+1], cur[len1+1];
    int i, j; 
    int cost;
    //初始化
    prev[0] = 0;
    for(i = 1; i <= len1; i++)
        prev[i] = i;
    cur[0] = 0;
    for (i = 1; i <= len2; i++)
    {
        cur[0] = i;
        for (j = 1; j <= len1; j++)
        {
            cost = 0;
            if (word2[i-1] != word1[i-1])
                cost = 1;
            cur[j] = min3(cur[j-1]+1, prev[j]+1, prev[j-1]+cost);
        }
        for (j = 0; j <= len1; j++)
            prev[j] = cur[j];
    }

    return cur[len1];
}
