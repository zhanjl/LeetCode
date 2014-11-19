void getRow(int rowIndex)
{
    int data[rowIndex+1];
    int i, j;
    data[0] = 1;
    data[1] = 1;
    for (i = 2; i <= rowIndex; i++)
    {
        for (j = 0; j < i - 1; j++)
            data[j] = data[j] + data[j+1];
        //在数组首插入1
        for (j = i; j >= 1; j--)
            data[j] = data[j-1];
        data[0] = 1;
    }

    for (i = 0; i <= rowIndex; i++)
        printf("%d ", data[i]);
    printf("\n");
}
