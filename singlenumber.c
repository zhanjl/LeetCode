#include <stdio.h>
#include <stdlib.h>
int signalnumber(int a[], int n)
{
    int i, res;
    res = a[0];
    for (i = 1; i < n; i++)
        res = res ^ a[i];
    return res;
}

int main()
{
    int data[] = {3, 1, 1, 2, 3};
    printf("%d\n", signalnumber(data, 5));
}
