//总体方法和没有重复元素的类似
//如果有重复元素的话，就不能使用算法二寻找最小元素，只有算法一这一种方法。
//时间复杂度为O(n)
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


//该题的discuss有个解题思路值得借鉴
//找到一个方法逐步排除元素，经过至多n次，就可以得到结果
//对于A[mid] > A[low]或者A[mid] < A[low]，都可以确定mid的位置
//只有A[mid] == A[low]是确定不了，但是如果A[mid] != target，则就
//排除A[low]，直接令low++即可。
bool search(int A[], int n, int target)
{
    int low, mid, high;
    
    low = 0, high = n - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (A[mid] == target)   
            return true;

        if (A[mid] < A[low])
        {
            if (target > A[mid] && target <= A[high])
                low = mid + 1;
            else 
                high = mid - 1;
        }
        else if (A[mid] > A[low])
        {
            if (target < A[mid] && target >= A[low])
                high = mid - 1;
            else
                low = mid + 1;
        }
        //A[mid] == A[low] != target
        else
            low++;
    }
    return false;
}
