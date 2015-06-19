
string extract(string &path, int start)
{
    string str;
    
    start++;    //忽略起始部分的'/'
    while (start < path.size() && path[start] != '/')
    {
        str.push_back(path[start++]);
    }

    return str;
}

string simplifyPath(string path)
{
    stack<string> stk;
    string str; 
    int start = 0;

    while (start < path.size()) {
        str = extract(path, start);
        start += str.size() + 1; 
        if (str == "." || str.size() == 0) {
            continue;
        } else if (str == "..") {
            if (!stk.empty()) {
                stk.pop();
            }
        } else {
            stk.push(str);
        }
    }

    stack<string> result_stk;
    while (!stk.empty()) {
        result_stk.push(stk.top());
        stk.pop();
    } 

    string result;
    
    while (!result_stk.empty()) {
        result.push_back('/');

        result += result_stk.top();
        result_stk.pop();
    }
    
    if (result.empty())
        result.push_back('/');

    return result;
}

