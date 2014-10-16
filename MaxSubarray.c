int maxSubArray(int A[], int n)
{
    int sum, beg, end, max;
    sum = 0;
    max = A[0];
    beg = end = 0;
    while (end < n) {
        sum += A[end];
        if (sum > max)
            max = sum;
        if (sum < 0) {
            sum = 0;
            end++;
            beg = end;
            continue;
        }
        end++;
    }
    return max;
}

//分治法
int max2(int a, int b)
{
    return a > b ? a : b;
}
int max3(int a, int b, int c)
{
    return max2(max2(a, b), c);
}

int submax(int A[], int l, int u)
{
    int mid, lmax, rmax, mmax;
    int i, sum, tem;
    if (l == u)
        return A[l];
    mid = (l + u) / 2;
    
    tem = sum = A[mid]; 
    for (i = mid-1; i >= l; i++)
    {
        sum += A[i];
        if (sum > tem)
            tem = sum;
    }
    mmax = tem;

    tem = sum = A[mid+1];
    for (i = mid+2; i <= u; i++)
    {
        sum += A[i];
        if (sum > tem)
            tem = sum;
    }
    mmax += tem;

    lmax = submax(A, l, mid);
    rmax = submax(A, mid+1, u);
    return max3(lmax, mmax, rmax);
}   

int maxSubArray(int A[], int n)
{
    return submax(A, 0, n-1);
}


