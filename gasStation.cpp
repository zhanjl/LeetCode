/*
 * 如果从A出发不能经过B，则下一个起始节点应该是B+1
 */
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int i, sum, total, start;
    sum = 0;
    total = 0;
    start = 0;
    for (i = 0; i < gas.size(); i++)
    {
        sum = sum + gas[i] - cost[i];
        if (sum < 0)
        {
            total += sum;
            sum = 0;
            start = i + 1;
        }
    }
     
    start = (total + sum) >= 0 ? start : -1;
    return start;
}

