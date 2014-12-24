
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    vector<int> left;
    int i, j, sum, start, oldstart;
    //首先求出从每个节点运动到下一个ie节点后所剩余的气量
    for (i = 0; i < gas.size(); i++)
        left.push_back(gas[i] - cost[i]);

    start = 0;  //初始起始节点设为0
    while (true)
    {
        vector<int> cur;
        sum = 0;
        i = start;
        while (true)
        {
            sum += left[i];
            //sum小于0,表示不能通过节点i
            if (sum < 0)
                break;
            //存储通过节点i所剩下的气量
            cur.push_back(sum);
            i = (i + 1) % gas.size();
            if (i == start)
                break;
        }
        //有两种特殊情况1,left[start] < 0，2,走完一圈
        if (i == start && cur.size() != 0)
            break;
        //寻找下一个起始节点
        for (j = 0; j < cur.size(); j++)
        {
            if (cur[j] < left[(start+j)%gas.size()])
                break;
        }
        oldstart = start;
        if (j == cur.size())
            start = (i + 1) % gas.size();
        else
            start = (start + j) % gas.size();

        if (start <= oldstart)
        {
            start = -1;
            break;
        }
    }

    return start;
}
