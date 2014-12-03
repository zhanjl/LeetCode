
string countAndSay(int n)
{
    int i, j, count;
    string result;
    result.push_back('0'+1);
    for (i = 1; i < n; i++)
    {
        string str;
        count = 1;
        for (j = 0; j < result.size()-1; j++)
        {
            if (result[j] != result[j+1])
            {
                str.push_back('0'+count);
                str.push_back(result[j]);
                count = 1;
                continue;
            }
            count++;
        }
        str.push_back('0'+count);
        str.push_back(result[j]);

        result = str;
    }

    return result;
}
