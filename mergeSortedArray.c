void merge(int A[], int m, int B[], int n)
{
    int C[m+n];
    int i, j, k;
    i = j = k = 0;
    while ( (i < m) && (j < n))
    {
        if (A[i] < B[j])
            C[k++] = A[i++];
        else
            C[k++] = B[j++];
    }

    while (i < m)
        C[k++] = A[i++];
    
    while (j < n)
        C[k++] = B[j++];

    for (i = 0; i < m+n; i++)
        A[i++] = C[i++];
}

//不使用额外空间，前提是A数组空间要大于等于m+n
void merge(int A[], int m, int B[], int n)
{
    int index = m + n - 1;
    m--;
    n--;
    while ((m >= 0) && (n >= 0))
    {
        if (A[m] > B[n])
            A[index--] = A[m--];
        else
            A[index--] = B[n--];
    }
    while (n >= 0)
        A[index--] = B[n--];
}
