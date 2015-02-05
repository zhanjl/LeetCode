//判断s[beg...end]是否是回文
bool isPalindrome(string& s, int beg, int end)
{
    int i, j;
    i = beg, j = end;
    while (i <= j) {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    } 
    return true;
}

//算法一，最朴素的方法，时间复杂度O(n^3)，空间复杂度O(1)
string longestPalindrome(string s)
{
    int maxlen;
    string result;
     
    maxlen = 0;
    for (int i = 0; i < s.size() - maxlen; i++) {
        for (int j = s.size() - 1; j >= i + maxlen; j--) {
            if (isPalindrome(s, i, j)) {
                maxlen = j - i + 1;
                result = string(s, i, j - i + 1);
                break;
            }
        }
    }
    return result;
}

//算法二，使用动态规划
//判断s[i...j]是否是回文，只需判断s[i]是否等于s[j]并且
//s[i+1, j-1]是否是回文，如果这两个条件都成立，则s[i..j]
//是回文，否则不是回文
//时间复杂度O(n^2)，空间复杂度O(n^2)
string longestPalindrome(string s)
{
    int len = s.size();
    bool palin[len][len];
    int beg, end;
    for (int i = 0; i < len; i++)
        palin[i][i] = true;
    beg = end = 0;
    for (int step = 1; step < len; step++) {
        for (int i = 0; i < len - step; i++) {
        //判断s[i...i+step]是否是回文
            if (s[i] != s[i+step]) {
                palin[i][i+step] = false;
                continue;
            }
            if ((i + 1) > (i + step - 1)) {
                palin[i][i+step] = true;
                beg = i;
                end = i+step;
                continue;
            }
            palin[i][i+step] = palin[i+1][i+step-1];
            if (palin[i][i+step]) {
                beg = i;
                end = i+step;
            }
        }
    }
    return string(s, beg, end - beg + 1); 
}

//优化动态规划，这个思路不好理解
//时间复杂度为O(n^2)，空间复杂度为O(1)
string longestPalindrome(string s)
{
    if (s.size() == 1)
       return s;
    
    int start, maxlen;
    int beg, end;
    maxlen = 0;
    for (int i = 1; i < s.size(); i++) {
        //偶数个 
        beg = i - 1;
        end = i; 
        while (beg >= 0 && end < s.size() && s[beg] == s[end]) {
            if (end - beg + 1 > maxlen) {
                start = beg;
                maxlen = end - beg + 1;
            }
            beg--;
            end++;
        }
        //奇数个
        beg = i - 1;
        end = i + 1;
        while (beg >= 0 && end < s.size() && s[beg] == s[end]) {
            if (end - beg + 1 > maxlen) {
                start = beg;
                maxlen = end - beg + 1;
            }
            beg--;
            end++;
        }
    }

    return string(s, start, maxlen);
}
