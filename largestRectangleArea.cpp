//这一题O(n^2)复杂度的算法很好想
//O(n)复杂度的算法思路如下
//对于每一个高度，求出以该高度为最小高度的矩形的最大面积
//所求的面积中最大的面积即为最终结果
//
//求以某个高度为最小高度的矩形最大面积的方法如下：
//分别求出该高度直方图前后比该值小的第一个高度值，
//这两个直方图的下标差就是矩形的宽度
//
//
//栈中存放的是非递减高度，也就是说栈中的前一个元素
//就是当前元素前面第一个比当前元素小的元素
int largestRectangleArea(vector<int> &height)
{
    stack<int>  stk;
    vector<int> hgt(height);
    if (hgt.size() == 0)
        return 0;

    hgt.push_back(0);
    int maxArea, curArea;
    int curheight;
    int i, len;

    i = 0;
    maxArea = 0;
    while (i < hgt.size())
    {
        if (stk.empty() || hgt[i] >= hgt[stk.top()])
        {
            stk.push(i++);
        }
        else
        {
            curheight = hgt[stk.top()];
            stk.pop();
            
            if (stk.empty())
               len = i;
            else
               len = i - stk.top() - 1;
            
            curArea = len * curheight;
            if (curArea > maxArea)
               maxArea = curArea; 
        }
    }

    return maxArea;
}
