
int binarysearch(int A[], int beg, int end, int target)
{
    int mid;
    while (beg <= end)
    {
        mid = (beg + end) / 2;
        if (A[mid] == target)
            return mid;
        else if (target < A[mid])
            end = mid - 1;
        else
            beg = mid + 1;
    }
    return -1;
}

//算法一：时间复杂度为O(n)，主要时间都话费在了寻找旋转的支点上了
int search(int A[], int n, int target)
{

    if (n == 0)
        return -1;
    if (n == 1)
    {
        if (A[0] == target)
            return 0;
        return -1;
    }
    int fbeg, fend, sbeg, send;
    int i;

    fbeg = 0;
    send = n - 1;
    for (i = 0; i < n - 1; i++)
    {
        if (A[i] > A[i+1])
            break;
    }
    //如果根本没绕某个支点旋转
    if (i == n - 1)
        return binarysearch(A, 0, n - 1, target);
    fend = i;
    sbeg = i + 1;

    if (target > A[fend] || target < A[sbeg])
        return -1;
    if (target < A[fbeg] || target > A[send])
        return -1;
    
    if (target >= A[fbeg] && target <= A[fend])
    {
        return binarysearch(A, fbeg, fend, target);
    }
     
    return binarysearch(A, sbeg, send, target);
}

//算法二：时间复杂度为O(lgn)，主要改进点是寻找旋转支点，其他代码不变
//int beg, mid, end;
//beg = 0, end = n - 1;
//while (beg < end)
//{
//  mid = (beg + end) / 2;
//  if (A[mid] > A[beg])
//      beg = mid + 1;
//  else if (A[mid] < A[end])
//      end = mid;
//}
//此时beg = end，指向最小元素，或者指向最后一个元素（如果没有旋转支点的话）。
