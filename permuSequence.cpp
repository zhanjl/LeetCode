#include <iostream>
#include <string>
using namespace std;
string getPermutation(int n, int k)
{
    int fact[9];
    int num[10] = {0};
    int i, j, kth, cnt;
    string res;
    fact[1] = 1;
    for (i = 2; i < 9; i++)
        fact[i] = fact[i-1] * i;

    if (n == 1) 
        return string("1");
    for (i = 1; i < n; i++)
    {
        kth = (k + fact[n-i] - 1) / fact[n-i];

        k = k % fact[n-i];
        if (k == 0)
            k = fact[n-i];
        cnt = 0; 
        for (j = 1; j <= n; j++)
        {
            if (num[j] == 0)
                cnt++;
            if (cnt == kth)
            {
                num[j] = 1;
                break;
            }
        }
        res.push_back('0' + j);
    }
    for (j = 1; j <= n; j++)
    {
        if (num[j] == 0)
            break;
    }
    res.push_back('0' + j);

    return res;
}

int main()
{
    cout << getPermutation(3, 1) << endl;
    return 0;
}
