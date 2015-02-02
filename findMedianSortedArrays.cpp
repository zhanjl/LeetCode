//O(m+n)时间复杂度算法
double findMedianSortedArrays(int A[], int m, int B[], int n)
{
    int *C = new int[m+n];
    int first, second, third;
    first = second = third = 0;
    while (first < m && second < n) {
        if (A[first] < B[second]) {
            C[third++] = A[first++];
        } else {
            c[third++] = B[second++];
        }
    }

    while (first < m) {
        C[third++] = A[first++];
    }

    while (second < n) {
        C[third++] = B[second++];
    }

    double result;
    if ((m+n) % 2 == 0)
        result = (C[(m+n)/2] + C[(m+n)/2-1]) / 2.0;
    else
        result = C[(m+n)/2];
    return result;
}

//O(log(m+n))复杂度算法

//寻找A[]和B[]中第K小的数 
int kthNum(int A[], int m, int B[], int n, int k)
{
    if (m > n) {
        return kthNum(B, n, A, m, k);
    }

    if (m == 0) {
        return B[k-1];
    }

    if (k == 1) {
        return min(A[0], B[0]);
    }
    
    int pa = k / 2;
    if (pa > m) {
        pa = m;
    }

    pb = k - pa;

    if (A[pa-1] < B[pb-1]) {
        return kthNum(A + pa, m - pa, B, n, k - pa);
    } else if (A[pa-1] > B[pb-1]) {
        return kthNum(A, m, B + pb, n - pb, k - pb);
    } else {
        return A[pa-1];
    }
}

double findMedianSortedArrays(int A[], int m, int B[], int n)
{
    if ((m + n) % 2 == 1)
        return kthNum(A, m, B, n, (m+n) / 2 + 1);
    else
        return (kthNum(A, m, B, n, (m+n) / 2) + kthNum(A, m, B, n, (m+n) / 2 + 1)) / 2.0;
}
