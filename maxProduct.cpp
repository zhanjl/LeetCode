#include <iostream>
#include <vector>
using namespace std;

int maxProduct1(vector<int>& nums)
{
    if (nums.size() == 0)
        return 0;
    
    int res, maxPrev, minPrev;

    minPrev = 0;
    res = maxPrev = nums[0];
    if (nums[0] < 0)
        minPrev = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < 0) {
            if (minPrev != 0) {
                int tmp = maxPrev;
                maxPrev = minPrev * nums[i];
                if (tmp > 0) {
                    minPrev = tmp * nums[i];
                } else {
                    minPrev = nums[i];
                }
            } else {
                if (maxPrev != 0)
                    minPrev = maxPrev * nums[i];
                else
                    minPrev = nums[i];
                maxPrev = nums[i];
            } 
        } else {
            if (maxPrev > 0) {
                maxPrev *= nums[i];
            } else {
                maxPrev = nums[i];
            }

            if (minPrev != 0)
                minPrev *= nums[i];
        }

        if (maxPrev > res)
            res = maxPrev;
    }
    
    return res;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int maxProduct(vector<int>& nums)
{
    int maxCur, minCur, res;
    if (nums.size() == 0)
       return 0;
    maxCur = minCur = res = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] >= 0) {
            maxCur = max(maxCur * nums[i], nums[i]);
            minCur = min(minCur * nums[i], nums[i]);
        } else {
            int temp = maxCur;
            maxCur = max(minCur * nums[i], nums[i]);
            minCur = min(temp * nums[i], nums[i]);            
        }

        res = max(maxCur, res);
    }

    return res;
}

int main()
{
    int n[] = {0, -2, -3};
    vector<int> nums(n, n + 3);
    int res = maxProduct(nums);
    cout << res <<endl; 
    return 0;
}
