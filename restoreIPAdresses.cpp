
void pushstr(string &data, string s, int beg, int end)
{
    while (beg <= end) {
        data.push_back(s[beg]);
        beg++;
    }
}

void popstr(string &data, int beg, int end)
{
    while (beg <= end) {
        data.pop_back();
        beg++;
    }
}

//s[beg, end]是否是一个有效的IP地址段
bool isvalid(string s, int beg, int end)
{
    if (end - beg >= 3)
        return false;
    int res = 0;
    while (beg <= end) {
        res = res * 10 + (s[beg] - '0');
        beg++;
    }

    if (res > 255)
        return false;
    return true;
}

vector<string> restoreIpAddresses(string s)
{
    vector<string> result;
    string      temp;
    for (int i = 0; i < 3 && i < s.size(); i++) {

        if (i != 0 && s[0] == '0')
            break;

        if (i == 2) {
            if (!isvalid(s, 0, i))
                break;
        }
        
        pushstr(temp, s, 0, i);
        temp.push_back('.');

        for (int j = i + 1; j < i + 4 && j < s.size(); j++) {

            if (j != (i + 1) && s[i+1] == '0')
               break; 

            if (j == i + 3) {
                if (!isvalid(s, i + 1, j))
                    break;
            }
            
            pushstr(temp, s, i + 1, j);
            temp.push_back('.');

            for (int k = j + 1; k < j + 4 && k < s.size(); k++) {

                if (k != (j +1) && s[j+1] == '0')
                    break;

                if (k == j + 3) {
                    if (!isvalid(s, j + 1, k))
                        break;
                }

                pushstr(temp, s, j + 1, k);
                temp.push_back('.');

                if ( (k + 1) < s.size() && isvalid(s, k + 1, s.size() - 1)) {
                    if (((k + 1) == s.size() - 1) || s[k+1] != '0') {
                        pushstr(temp, s, k + 1, s.size() -1);
                        result.push_back(temp);
                        popstr(temp, k + 1, s.size() - 1);
                    }
                }

                popstr(temp, j + 1, k);
                temp.pop_back();
            }
             
            popstr(temp, i + 1, j);
            temp.pop_back();
        }

        popstr(temp, 0, i);
        temp.pop_back();
    }

    return result;
}
