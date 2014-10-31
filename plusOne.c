void plusOne(int digits[], int n)
{
    int res[n+1];
    int i;

    res[0] = 0;
    for (i = 0; i < n; i++)
        res[i+1] = digits[i];

    for (i = n; i >= 0; i--)
    {
        if (res[i] == 9)
        {
            res[i] = 0;
            continue;
        }
        res[i] += 1;
        break;
    }

    if (res[0] == 0)
    {
        for (i = 0; i < n; i++)
            res[i] = res[i+1];
    }
}
