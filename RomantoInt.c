//I 1 V 5 X 10 L 50 C 100 D 500 M 1000
struct roman {
    char c;
    int i;
};

struct roman conv[7] = { {'I', 1},{'V', 5},{'X', 10},
                         {'L', 50},{'C', 100},{'D', 500},{'M', 1000}};
int findnum(char c)
{
    int i;
    for (i = 0; i < 7; i++)
        if (conv[i].c == c)
            return conv[i].i;
    return 0;
}
int romanToInt(char *s)
{
    int ret, cur, next;
    ret = 0;
    while (*s) {
        cur = findnum(*s);
        next = findnum(*(s+1));  
        if (next == 0) {
            ret += cur;
            break;
        } else if (cur < next) {
            ret += next - cur;
            s = s + 2;
        } else {
            ret += cur;
            s = s + 1;
        }
    }
    return ret;
}

//第二种方法从后向前计算，代码简洁很多
int romanToInt(char *s)
{
    int ret, cur, prev, i;
    i = strlen(s) - 1;
    ret = 0;
    prev = 0;
    while (i >= 0) {
        cur = findnum(s[i]);
        if (cur >= prev) 
            ret += cur;
        else
            ret -= cur;
        prev = cur;
        i--;
    }

    return ret;
}
