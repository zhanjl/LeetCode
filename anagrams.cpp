//使用map容器
vector<string> anagrams(vector<string> &strs)
{
    vector<string> ret;
    map<string, vector<string> > mp;

    for (vector<string>::const_iterator it = strs.begin(); it != strs.end(); it++)
    {
        string temp(*it);
        sort(temp.begin(), temp.end());
        mp[temp].push_back(*it);
    }

    for (map<string, vector<string> >::const_iterator it = mp.begin(); it != mp.end(); it++)
    {
        if ((it->second).size() > 1)
            ret.insert(ret.end(), it->second.begin(), it->second.end());
    }

    return ret;
}
