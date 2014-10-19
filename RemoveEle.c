//方法1 最简单的方法，空间复杂度为O(n)，时间复杂度为O(n)
int removeElement(int A[], int n, int elem)
{
    int B[n];
    int i, j;
    for (i = 0; i < n; i++)
        if (A[i] != elem)
            B[j++] = A[i];

    for (i = 0; i < j; i++)
        A[i] = B[i];

    return j;
}

//方法2, 空间复杂度O(1)，时间复杂度O(n)
int removeElement(int A[], int n, int elem)
{
    int i, j;
    i = j = 0;
    for (i = 0; i < n; i++) {
        if (A[i] != elem) {
            A[j++] = A[i];
        }
    }
    return j;
}
//方法3 空间复杂度为O(1)，时间复杂度为O(nlgn)
//先快排，然后再二分查找
int partition(int A[], int low, int high)
{
    int i, j, tem;
    i = low;
    for (j = low + 1; j <= high; j++) {
        if (A[j] < A[low]) {
            i++;
            tem = A[j];
            A[j] = A[i];
            A[i] = tem; 
        }  
    }

    tem = A[low];
    A[low] = A[i];
    A[i] = tem;
    return i;
}

void quicksort(int A[], int low, int high)
{
    int tem;
    if (low >= high)
        return;
    tem = partition(A, low, high);
    quicksort(A, low, tem -1);
    quicksort(A, tem+1, high);
}

int binarysearch(int A[], int n, int val)
{
    int low, mid, up;
    low = 0, up = n - 1;

    while (low <= up) {
        mid = (low + up) / 2;
        if (val > A[mid])
            low = mid + 1;
        else if (val < A[mid])
            up = mid - 1;
        else 
            return mid;
    }
    return -1;
}
int removeElement(int A[], int n, int elem)
{
    int i, l, u, cnt;
    quicksort(A, 0, n-1);
    i = binarysearch(A, n, elem);
    if (i == -1)
        return n;
    l = i;
    u = i;
    while ((l >= 0) && (A[l] == elem))
        l--;
    l++;
    while ( (u < n) && (A[u] == elem))
        u++;
    
    cnt = u - l;
    
    while (u < n) {
        A[u-cnt] = A[u];
        u++; 
    }

    return n - cnt;
}
