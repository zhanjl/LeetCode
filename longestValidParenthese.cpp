
int longestValidParentheses(string s)
{
    int result;
    int beg;
    int sum;
    
    sum = 0;
    beg = 0;
    result = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            sum++;
        } else {
            sum--;
        }

        if (sum == 0) {
            if ((i - beg + 1) > result) {
                result = i - beg + 1;
            }
        } else if (sum < 0) {
            beg = i + 1;
            sum = 0;
        }
    }
    
    int size = beg;
    if (sum > 0) {
        sum = 0;
        beg = s.size() - 1;
        for (int i = s.size() - 1; i >= size; i--) {
            if (s[i] == ')') {
                sum++;
            } else {
                sum--;
            }

            if (sum == 0) {
                if ((beg - i + 1) > result) {
                    result = beg - i + 1;
                }
            } else if (sum < 0) {
                beg = i - 1;
                sum = 0;
            }
        }
    }
    return result;
}

