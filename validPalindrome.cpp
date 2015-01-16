#include <iostream>
#include <string>
using namespace std;
bool isPalindrome(string s)
{
    if (s.size() == 0)
        return true;
    
    int len, beg, end;
    len = s.size();
    beg = 0;
    end = len - 1;

    while (beg < len)
    {
        if (isalnum(s[beg]))
            break;
        beg++;
    }

    while (end >= 0)
    {
        if (isalnum(s[end]))
            break;
        end--;
    }

    while (beg < end)
    {
        if (isalpha(s[beg]))
        {
            if (toupper(s[beg]) != toupper(s[end]))
                return false;
        }
        else if (s[beg] != s[end])
            return false;
        beg++;
        end--;
        while (beg < len)
        {
            if (isalnum(s[beg]))
                break;
            beg++;
        }

        while (end >= 0)
        {
            if (isalnum(s[end]))
                break;
            end--;
        }

    }
    return true;
}
int main()
{
    string str("Aa");
    isPalindrome(str);
    return 0;
}
