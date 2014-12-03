string addBinary(string a, string b) 
{
    int i, j;
    int num1, num2, num3;
    string c;
    num2 = 0;
    i = a.size() - 1;
    j = b.size() - 1;
    while ((i>=0) && (j>=0))
    {
        num1 = a[i] - '0';
        num3 = b[j] - '0';
        c.push_back((num1+num2+num3)%2 + '0');
        num2 = (num1 + num2 + num3) / 2;
        i--;
        j--;
    }
    
    while (i >= 0)
    {
        num1 = a[i] - '0';
        c.push_back((num1+num2)%2 + '0');
        num2 = (num1 + num2) / 2;
        i--;
    }

    while (j >= 0)
    {
        num3 = b[j] - '0';
        c.push_back((num3+num2)%2 + '0');
        num2 = (num3 + num2) / 2;
        j--;
    }
    
    if (num2 != 0)
        c.push_back(num2 + '0');

    reverse(c.begin(), c.end());    
    return c;
}
