//这一题从每个点的角度来考虑比较容易解答
//每个点上的蓄水量可以这样求：
//求出该点左边（包括该点）的最大元素
//求出该点右边（包括该点）的最大元素
//这两个最大元素的较小值就是该点所处凹槽的水平线
//水平线减去该点的值就是在该点上的蓄水量
int trap(int A[], int n)
{
    int ltr[n], rtl[n];
    int i, res, min;
    ltr[0] = A[0];
    for (i = 1; i < n; i++)
        ltr[i] = (A[i] > ltr[i-1] ? A[i] : ltr[i-1]);

    rtl[n-1] = A[n-1];
    for (i = n - 2; i >= 0; i--)
        rtl[i] = (A[i] > rtl[i+1] ? A[i] : rtl[i+1]);

    res = 0;
    for (i = 1; i <= n-2; i++)
    {
        min = (ltr[i] < rtl[i] ? ltr[i] : rtl[i]);
        res += min - A[i];
    }
    return res;
}
