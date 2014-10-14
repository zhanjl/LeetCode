int climbStars(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    return climbStars(n-1) + climbStars(n-2);
}

//迭代法
int climbStars1(int n)
{
    int prev, pprev, cur;
    int i;
    if (n == 0 || n == 1)
        return 1;
    pprev = 1;
    prev = 1;
    for (i = 2; i <= n; i++)
    {
        cur = prev + pprev;
        pprev = prev;
        prev = cur;
    } 
    return cur;
}
