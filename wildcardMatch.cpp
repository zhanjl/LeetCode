#include <iostream>
#include <string>
using namespace std;
bool partMatch(string s, int sbeg, string p, int pbeg)
{
    while (sbeg != s.size() && pbeg != p.size()) {
        if (p[pbeg] == '*')         //*号单独处理
            break;
        if (s[sbeg] != p[pbeg] && p[pbeg] != '?')
            return false;
        sbeg++;
        pbeg++;
    }

    if (sbeg == s.size() && pbeg == p.size())
        return true;

    if (sbeg == s.size() || pbeg == p.size())
        return false;

    for (int i = sbeg; i <= s.size(); i++) {
        if (partMatch(s, i, p, pbeg + 1) == true)
            return true;
    }

    return false;
}

bool isMatch1(string s, string p)
{
    return partMatch(s, 0, p, 0); 
}

bool isMatch2(string s, string p)
{
    if (s.size() == 0 && p.size() == 0)
        return true;

    if (s.size() == 0 || p.size() == 0)
        return false;

    int sSize, pSize;
    sSize = s.size();
    pSize = p.size();

    bool first[sSize+1], second[sSize+1];
    first[0] = true;
    for (int i = 1; i <= sSize; i++)
        first[i] = false;

    for (int i = 1; i <= pSize; i++) {
        for (int j = 0; j <= sSize; j++) {
            if (p[i-1] == '*') {
                int k;
                for (k = 0; k <= j; k++) {
                    if (first[k] == true)
                        break;
                }

                if (k == j + 1)
                    second[j] = false;
                else
                    second[j] = true;
            } else if (p[i-1] == '?') {
                if (j == 0)
                    second[j] = false;
                else
                    second[j] = first[j-1];
            } else {
                if (j == 0)
                    second[j] = false;
                else 
                    second[j] = first[j-1] && (p[i-1] == s[j-1]);
            }
        }

        for (int j = 0; j <= sSize; j++)
            first[j] = second[j];
    }

    return first[sSize];
}

bool isMatch(string s, string p)
{
     
}

int main()
{
    string s, p;
    //while (cin >> s >> p)
     (cin >> s >> p);
        cout << isMatch2(s, p) << endl; 
    return 0;
}
