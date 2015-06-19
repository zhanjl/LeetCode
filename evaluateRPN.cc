
int strtoint(string str)
{
    int res;
    bool isnegtive;
    res = 0;
    isnegtive = false;
    
    int i = 0;
    if (str[i] == '-') {
        isnegtive = true;
        i++;
    }

    while (i < str.size()) {
        res = res * 10 + str[i] - '0';
        i++;
    }
    
    if (isnegtive)
        res = -res;
    return res;
}

int evalRPN(vector<string>& tokens)
{
    int res;
    int loperand, roperand;
    stack<int> stk;
    
    res = 0;
    for (vector<string>::iterator it = tokens.begin();
                        it != tokens.end(); it++)
    {
        if ( *it == "+" || *it == "-" || *it == "*" || *it == "/")
        {
            roperand = stk.top();
            stk.pop();
            loperand = stk.top();
            stk.pop();
            if (*it == "+")
                res = loperand + roperand;
            else if (*it == "-")
                res = loperand - roperand;
            else if (*it == "*")
                res = loperand * roperand;
            else 
                res = loperand / roperand;
            stk.push(res);
        } else {
            stk.push(strtoint(*it));
        }
    }
    res = stk.top();
    return res;
}
