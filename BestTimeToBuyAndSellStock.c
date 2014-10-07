//测github contribution显示:
#include <stdio.h>
#include <stdlib.h>
int maxProfit(int prices[], int n)
{
    int i, min, ret;
    min = prices[0];
    ret = 0;
    for (i = 1; i < n; i++)
    {
        if (prices[i] < min)
            min = prices[i];
        else if ((prices[i] - min) > ret)
            ret = prices[i] - min;
    }
    return ret;
}

int main()
{
    int data[] = {1, 2};
    printf("%d\n", maxProfit(data, 2));
}
