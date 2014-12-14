
//算法一时间复杂度为O(n^2lgn)
int binarySearch(vector<int> &num, int beg, int end, int target)
{
    int mid;
    while (beg <= end)
    {
        mid = (beg + end) / 2;
        
        if (num[mid] == target)
            return mid;
        else if (target > num[mid])
            beg = mid + 1;
        else
            end = mid - 1;
    }
    return beg;
}
int distance(int a, int b)
{
    if (a > b)
        return a - b;
    else
        return b - a;
}
int twoSumClosest(vector<int> &num, int beg, int end, int target)
{
    int i, mid;
    int sum, dis, temp, res;
    dis = 0x7fffffff;
    for (i = beg; i < end; i++)
    {
        mid = binarySearch(num, i+1, end, target - num[i]);
        if (mid == i+1)
            sum = num[i] + num[mid];
        else if (mid == end + 1)
            sum = num[i] + num[mid-1];
        else {
            temp = num[i] + num[mid];
            sum = num[i] + num[mid-1];
            if (distance(temp, target) < distance(sum, target))
                sum = temp;
        }
        
        if (distance(sum, target) < dis)
        {
            dis = distance(sum, target);
            res = sum;
        }
    }
    return res;
} 
int threeSumClosest(vector<int> &num, int target) {
    //先排序
    
    sort(num.begin(), num.end());
    int i;
    int sum, res, dis;
    dis = 0x7fffffff;
    for (i = 0; i < num.size() - 2; i++)
    {
        sum = twoSumClosest(num, i + 1, num.size() - 1, target - num[i]);
        sum += num[i];
        if (distance(sum, target) < dis)
        {
            dis = distance(sum, target);
            res = sum;
        }
    }
    return res;
}


//算法二，时间复杂度为O(n^2)
//首先对输入数据进行排序
//num[0]...num[i]...num[j]...num[n-1]
//如果num[i] + num[j] > target，则令j--
//如果num[i] + num[j] < target，则令i++
int threeSumClosest(vector<int> &num, int target)
{
    sort(num.begin(), num.end());
    int i, j, k;
    int sum, dif, t, res;
    dif = 0x7fffffff;

    for (i = 0; i < num.size() - 2; i++)
    {
        t = target - num[i];
        j = i + 1;
        k = num.size() - 1;

        while (j < k)
        {
            if ((num[j] + num[k]) == t)
                return target;

            sum = num[i] + num[j] + num[k];
            if (abs(sum - target) < dif)
            {
                res = sum;
                dif = abs(sum - target);
            }
            if ((num[j] + num[k]) < t)
                j++;
            else
                k--;
        }
    }
    return res;
}
