vector<string> generateParenthesis(int n) 
{
        vector<vector<string> > result;
        vector<string> nu;
        string first, second, temp;
        int i, j, k, p;
        
        result.push_back(nu) 
        for (i = 1; i <= n; i++)
        {
            vector<string> pare;
            for (j = 1; j < i - 1; j++)     //j == 0 和 j == i - 1这两种情况单独处理
            {
                for (k = 0; k < result[j].size(); k++)
                {
                    first = result[j][k];
                    for (p = 0; p < result[i-1-j].size(); p++)
                    {
                        second = result[i-1-j][p];
                        temp = "(" + first + ")" + second;
                        pare.push_back(temp);
                    }
                }
            }
            
            if (i == 1)
                pare.push_back("()");
            else
            {
                //处理j == 0 这种情况 result[i] = "(" + ")" + result[i-1]
                for (j = 0; j < result[i-1].size(); j++)
                {
                    second = result[i-1][j];
                    temp = "()" + second;
                    pare.push_back(temp);
                }
                //处理j == i - 1 这种情况 result[i] = "(" + result[i-1] + ")"
                for (j = 0; j < result[i-1].size(); j++)
                {
                    first = result[i-1][j];
                    temp = "(" + first + ")";
                    pare.push_back(temp);
                }
            }
            result.push_back(pare);
        }
        return result[n];
 }

