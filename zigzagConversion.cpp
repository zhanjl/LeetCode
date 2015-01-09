string convert(string s, int nRows)
{
    int strsize, block;
    int i, j;
    int step, index;
    strsize = s.size();
    string *res = new string[strsize];
    
    if (nRows <= 1)
        return s;
    index = 0;
    block = 2 * nRows - 2;
    //放入第一行的字符串
    for (i = 0; i < strsize; i += block)
        res[index++].push_back(s[i]);
    //放入第二至倒数第二行的字符串
    for (i = 1; i < nRows - 1; i++)
    {
        step = block - 2 * i; 
        j = i;
        while (j < strsize)
        {
            res[index++].push_back(s[j]);
            j += step;
            step = block - step;
        }
    }
    //放入倒数第一行的字符串
    for (i = nRows - 1; i < strsize; i+= block)
        res[index++].push_back(s[i]);
    
    s.clear();
    for (i = 0; i < strsize; i++)
        s.push_back(res[i][0]);
    delete [] res;
    return s;
}
