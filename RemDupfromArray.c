int removeDuplicates(int A[], int n)
{
    if (n == 0)
        return 0;
    int i, j;
    i = 0;
    j = 1;
    while (j < n) {
        if (A[i] != A[j]) {
            i++;
            A[i] = A[j];
        }
        j++;
    }
    return i+1;
}
