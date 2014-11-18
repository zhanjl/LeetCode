int removeDuplicates(int A[], int n)
{
    int i, j, flag;
    i = 0, j = 1;
    flag = 0;
    while (j < n)
    {
        if (A[i] != A[j])
        {
            i++;
            A[i] = A[j];
            flag = 0;
        } 
        else if (flag == 0)
        {
            i++;
            A[i] = A[j];
            flag = 1;
        }
        j++;
    }
    return i + 1;
}

