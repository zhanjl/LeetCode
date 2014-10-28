//时间复杂度为O(n)的解法
int findMin(int A[], int n)
{
    int i;
    for (i = 0; i < n - 1; i++)
    {
        if (A[i] > A[i+1])
            break;
    }
    if (i == n - 1)
       return A[0]; 
    return A[i+1];
}

//时间复杂度为O(lgn)的解法
int findMin(int A[], int n)
{
    int low, mid, high;
    low = 0;
    high = n - 1;
    while (low < high)
    {
        mid = (low + high) / 2;
        if (A[low] < A[high])
            break;
        if (A[mid] < A[high] && A[mid] < A[low])
            high = mid;
        else
            low = mid + 1;
    }
    return A[low];
}
