int canJump(int A[], int n)
{
    int index;
    int jmp, maxlen;
    int flag[n];
    for (index = 0; index < n; index++)
        flag[index] = 0;

    flag[0] = 1;
    index = 0;
    while (index < n)
    {
        if (flag[index] == 0)
            break;
        maxlen = A[index];
        for (jmp = maxlen; jmp >= 1; jmp--)
        {
            if ( (index + jmp) >= n )
            {
                jmp = n - index;
                continue;
            }
            if (flag[index+jmp] == 1)
                break;
            flag[index+jmp] = 1;
        }
        index++;
    }

    if (index == n)
        return 1;
    return 0;
}

//解法二，进一步优化，思想上解法一相同
int canJump(int A[], int n)
{
    int maxreach;
    int index;
    index = maxreach = 0;
    for (index = 0; index < n && index <= maxreach; index++)
        maxreach = ( (index + A[index]) > maxreach ? (index + A[index]) : maxreach);

    if (index == n)
        return 1;
    return 0;
}
