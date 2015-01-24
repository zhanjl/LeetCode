
bool wordBreak(string s, unordered_set<string> &dict)
{
    if (s.size() == 0)
        return true;
    string::size_type size;
    size = s.size();

    bool temp[size];
    int i, j;
    
    temp[0] = dict.count(string(s, 0, 1));

    for (i = 1; i < size; i++)
    {
        temp[i] = false;
        for (j = i - 1; j >= 0; j--)
        {
            if (temp[j] && dict.count(string(s, j+1, i - j)))
            {
                temp[i] = true;
                break;
            }
        }
        
        if (temp[i] == false)
            temp[i] = dict.count(string(s, 0, i+1));
    }

    return temp[size - 1];
}

