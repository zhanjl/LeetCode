#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
int reverse(int x)  //主要是要考虑溢出的情况
{
    long long ret = 0;
    while (x)
    {
        ret = ret * 10 + x % 10;
        x = x/10;
    }
    if (ret > INT_MAX)
       return INT_MAX;
    if (ret < INT_MIN)
       return INT_MIN; 
    return ret; 
}

int main()
{
    printf("%d\n", reverse(-1000000003));
}
