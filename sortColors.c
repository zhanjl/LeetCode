
//方法一使用计数排序
void sortColors(int A[], int n)
{
    int B[3];
    int i, j;
    for (i = 0; i < 3; i++)
        B[i] = 0;
    for (i = 0; i < n; i++)
        B[A[i]]++;
    
    j = 0;
    for (i = 0; i < 3; i++) {
        while (B[i] > 0) {
            A[j++] = i;
            B[i]--;
        }
    }
}

//方法二，只需要扫描一趟数组
void sortColors(int A[], int n)
{
    int i, j, temp;
    i = 0;
    while (i < n)
    {
        if (A[i] == 1)
        {
            i++;
            continue;
        }
        if (A[i] == 0)
        {
            j = 0;
            while ( j < i && A[j] == 0 )
                j++;
        } 
        else if (A[i] == 1)
        {
            j = n - 1;
            while (j > i && A[j] == 2)
                j--;
        } 
        //swap A[j] and A[i]
        if (i == j) 
        {
            i++;
            continue;
        }
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}


//方法三 太巧妙了，很难想出来
void sortColors(int A[], int n)
{
    int red, white, blue;
    int i;
    red = white = blue = -1;
    for (i = 0; i < n; i++)
    {
        if (A[i] == 0)
        {
            A[++blue] = 2;
            A[++white] = 1;
            A[++red] = 0;
        }
        else if (A[i] == 1)
        {
            A[++blue] = 2;
            A[++white] = 1;
        }
        else 
        {
            A[++blue] = 2;
        }
    }
}
