//这一题的难度在时间复杂度为O(logn)
//找到目标值的一个下表后，依次再用二分查找
//寻找前界和后界

int binarysearch(int A[], int beg, int end, int target)
{
    int mid;

    while (beg <= end)
    {
        mid = (beg + end) / 2;
        if (target == A[mid])
            return mid;
        else if (target > A[mid])
            beg = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}
void searchRange(int A[], int n, int target)
{
    if (n == 0)
    {
        printf("-1 -1\n");
        return;
    }
    int left, mid, right;

    mid = binarysearch(A, 0, n-1, target);
    if (mid == -1)
    {
        printf("-1 -1\n");
        return;
    }

    left = mid - 1;
    right = mid + 1;

    while (left >= 0)
    {
        mid = binarysearch(A, 0, left, target);
        if (mid == -1)
            break;
        left = mid - 1;
    }
    while (right < n)
    {
        mid = binarysearch(A, right, n-1, target);
        if (mid == -1)
            break;
        right = mid + 1;
    }

    printf("%d %d\n", left + 1, right - 1);
    return;
}
