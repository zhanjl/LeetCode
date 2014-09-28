#include <stdio.h>

int singleNumber(int A[], int n) 
{
        int i, j;
        int res = 0;
        int count; 
        for (i = 0; i < 32; i++)
        {
            count = 0;
            for (j = 0; j < n; j++)
            {
                if ( ((A[j]>>i)&0x1) == 1)
                    count += 1;
            }
            res |= ((count % 3) << i);
        }
        return res;
 }
int main()
{
    int data[] = {1, 2, 2, 3, 1, 2, 1};
    printf("%d\n", singleNumber(data, 7));
    return 0;
}
