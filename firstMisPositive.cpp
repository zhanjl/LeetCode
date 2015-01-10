
//题目要求使用O(n)的时间复杂度和O(1)的空间复杂度
//既然不能使用额外的空间，那就只能借助原数组空间
//把i+1的数字放到第i个索引处，最后遍历数组，查找
//不符合条件的第一个元素，即为结果
//
//交换A[i]和A[j]
void swap(int A[], int i, int j)
{
    int temp;
    temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}
int firstMissingPositive(int A[], int n)
{
    int i;
    i = 0;
    while (i < n)
    {
        //此时要交换A[i]
        if ( A[i] > 0 && A[i] != (i + 1))
        {
            //如果A[i]比n大或者要交换的元素值相等，直接跳过
            if (A[i] > n || A[A[i]-1] == A[i])
                i++;
            else
                swap(A, i, A[i] - 1);
        }
        else
            i++;
    } 

    for (i = 0; i < n; i++)
    {
        if (A[i] != (i + 1))
            break;
    }
    
    return i + 1;
}
