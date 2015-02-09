
int atoi(const char *str)
{
    long long result;
    int index;
    int flag;
    bool hassignal; //是否以+或-符号开头
    index = 0;
    int len = strlen(str);
    //消除开头的空格
    while (str[index] == ' ' && index < len)
        index++;
    hassignal = true;
    //判断第一个字符
    if (str[index] == '-') {
        index++;
        flag = -1;
    } else if (str[index] == '+') {
        index++;
        flag = 1;
    } else if (str[index] >= '0' && str[index] <= '9')
        hassignal = false;
        flag = 1;
    } else {
        return 0;
    }
    //消除空格                                  原题要去掉这两行才能通过，但是我觉得加上比较合理
    //while (str[index] == ' ' && index < len)
    //    index++;
    if (hassignal && index < len) {                 //如果符号后面的不是有效数字
        if (str[index] > '9' || str[index] < '0')
           return 0; 
    }
    result = 0;
    while (index < len) {
        if (str[index] > '9' || str[index] < '0') {
            break;
        }
        result = 10 * result + flag * (str[index] - '0');
        if (result > INT_MAX)
            return INT_MAX;
        else if (result < INT_MIN)
            return INT_MIN;
        index++;
    }
    return static_cast<int> (result);
}
