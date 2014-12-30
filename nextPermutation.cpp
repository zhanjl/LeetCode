
void nextPermutation(vector<int> &num)
{
    int len;
    int i, j;
    int temp;
    len = num.size();
    if (len == 0 || len == 1)
        return;

    for (i = len - 2; i >= 0; i--)
    {
        if (num[i] < num[i+1])
            break;
    }

    if (i == -1)
    {
        reverse(num.begin(), num.end());
        return;
    }

    j = len - 1;
    while (num[j] <= num[i])
        j--;

    temp = num[j];
    num[j] = num[i];
    num[i] = temp;
    reverse(num.begin() + i + 1, num.end());
    return;
}
