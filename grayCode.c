void grayCode(int n)
{
    int size = 2 ^ n;
    int res[size];
    int index, inc;
    int i, j;
    index = 0;
    res[0] = 0;

    for (i = 0; i < n; i++)
    {
        inc = 1 << i;
        for (j = index; j >= 0; j--)
            res[++index] = res[j] + inc;
    }

    for (i = 0; i <= index; i++)
        printf("%d\n", res[i]);
}

