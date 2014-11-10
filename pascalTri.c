void generate(int numRows)
{
    int data[numRows][numRows];
    int i, j;
    memset(data, 0, numRows * numRows * sizeof(int));
    data[0][0] = 1;
    if (numRows == 1)
        return;
    data[1][0] = data[1][1] = 1;
    for (i = 2; i < numRows; i++)
    {
        data[i][0] = 1;
        for (j = 1; j < i; j++)
            data[i][j] = data[i-1][j-1] + data[i-1][j];
        data[i][i] = 1;
    }
    for (i = 0; i < numRows; i++)
    {
        for (j = 0; j < numRows; j++)
            printf("%d ", data[i][j]);
        printf("\n");
    }
}

