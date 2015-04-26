int largetsRectangle(vector<int> &height)
{
    stack<int>  stk;

    height.push_back(-1);

    int curres, res;
    int i = 0;
    int h, len;
    res = 0;
    while ( i < height.size()) {
        if (stk.empty() || height[i] >= height[stk.top()]) {
            stk.push(i++);
        } else {
            h = height[stk.top()];
            stk.pop();
            
            if (stk.empty())
                len = i;
            else
                len = i - stk.top() - 1;

            curres = h * len;
            if (curres > res)
                res = curres;
        }
    }

    return res;
}

int maximalRectangle(vector<vector<char> > &matrix)
{
    vector<int> height;
    int res, curres;
    
    if (matrix.size() == 0)
        return 0;
    
    for (int i = 0; i < matrix[0].size(); i++) {
        if (matrix[0][i] == '0')
            height.push_back(0);
        else
            height.push_back(1);
    }

    res = largetsRectangle(height);

    for (int i = 1; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] == '0')
                height[j] = 0;
            else
                height[j]++;
        }
        
        curres = largetsRectangle(height);
        if (curres > res)
            res = curres;
    }

    return res;
}

