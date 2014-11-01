//O(n^2)的解法, 时间复杂度太高
int maxArea(int height[], int n)
{
    if (n == 0)
        return 0;
    int i, j;
    int max, lowline, cur;
    lowline = (height[0] < height[1]) ? height[0] : height[1];
    max = lowline;

    for (i = 2; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            lowline = (height[j] < height[i]) ? height[j] : height[i];
            cur = (i - j) * lowline;
            if (cur > max)
                max = cur;
        }
    }

    return max;
}

//O(n)时间复杂度算法，看待问题的角度不一样
//假设n == 5
//  1 2 3 4 5
//1 x ? ? ? ?
//2 x x ? ? ?
//3 x x x ? ?
//4 x x x x ?
//5 x x x x x
//最原始的解法是计算出每个?处的值，然后取最大值，该解法的时间复杂度为O(n^2)
//其实没必要计算每一处？，例如先计算[1][5]处的值，如果1点的高度小于5点，那么
//[1][2..4]的值一定小于[1][5]，就没必要计算了，可以想想为什么？
//同理，如果1点的高度大于5点，那么[2..5][5]处的值一定小于[1][5]，没必要计算
int maxArea(int height[], int n)
{
    int left, right, cur, result, lowheight;

    result = 0;
    left = 0;
    right = n - 1;
    while (left < right)
    {
        lowheight = (height[left] < height[right]) ? height[left] : height[right];
        cur = lowheight * (right - left);
        if (cur > result)
            result = cur;
        if (height[left] < height[right])
            left++;
        else
            right++;
    }

    return result;
}
