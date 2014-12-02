  string longestCommonPrefix(vector<string> &strs) {
        string result;
        int i, j;
        if (strs.size() == 0)
            return result;
        
        for (i = 0; i < strs[0].size(); i++)
        {
            for (j = 1; j < strs.size(); j++)
            {
                if (i >= strs[j].size())
                    break;
                if (strs[0][i] != strs[j][i])
                    break;
            }
            
            if (j != strs.size())
                break;
            result.push_back(strs[0][i]);
        }
        
        return result;
    }
