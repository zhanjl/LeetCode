#include <stdio.h>
#include <stdlib.h>

int maxProfit(int prices[], int n)
{
    int i, min, max, ret;
    
    ret = 0;
    min = max = prices[0];
    for (i = 1; i < n; i++)
    {
        if (prices[i] > max)
            max = prices[i];
        else
        {
            ret = ret + max - min;
            max = min = prices[i];
        }
    }
    ret += max - min;
    return ret;
}

int main()
{
    int data[] = {2, 4, 1, 5};
    printf("%d\n", maxProfit(data, 4));
    return 0;
}
