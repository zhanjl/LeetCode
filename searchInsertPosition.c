int searchInsert(int A[], int n, int target)
{
    int low, high, mid;
    if (n == 0)
        return 1;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high) / 2;
        if (A[mid] == target)
            return mid;
        else if (A[mid] < target)
            low = mid + 1;
        else
            hig = mid - 1;
    }
    return low;
}
