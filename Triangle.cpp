//本题就是一个简单的动态规划应用
int minimumTotal(vector<vector<int> > &triangle) {
     vector<int> cur;
     cur.push_back(triangle[0][0]);
     for (vector<vector<int> >::size_type i = 1; i < triangle.size(); i++)
     {
         vector<int> temp(cur);
         cur[0] = temp[0] + triangle[i][0];
         for (vector<int>::size_type j = 1; j < triangle[i].size() - 1; j++)
         {
             if ((temp[j-1]+triangle[i][j]) < (temp[j]+triangle[i][j]))
                 cur[j] = temp[j-1]+triangle[i][j];
             else
                 cur[j] += triangle[i][j];
         }
         cur.push_back(triangle[i][triangle[i].size()-1] + temp[i-1]);
     }
     
     int res;
     res = cur[0];
     for (vector<int>::size_type i = 1; i < cur.size(); i++)
     {
         if (cur[i] < res)
             res = cur[i];
     }
     return res;
 }
