//注意，负数不属于回文数
//算法一，反转x，但是要注意反转后的x可能会溢出
int isPalindrome(int x)
{
    long long y;
    int temp;
    temp = x;
    y = 0;

    while (temp != 0)
    {
        y = 10 * y + temp % 10;
        temp = temp / 10;
    }
    return y == x;
}

//算法二，不反转x，那就一位一位的比较
int isPalindrome(int x)
{
    if (x == 0)
        return 1;
    if (x < 0)
        return 0;
    
    int small, big, size;
    int temp, i;

    small = big = 1;
    size = 0;

    while (temp)
    {
        size++;
        temp /= 10;
        if (temp)
            big *= 10;
    }

    for (i = 1; i <= size / 2; i++)
    {
        if ((x/big)%10 != (x/small)%10)
            return 0;
    }
    return 1;
}
