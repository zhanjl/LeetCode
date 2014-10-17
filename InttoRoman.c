struct roman {
    char    c;
    int     val;
};
struct roman rm[] = { {'M', 1000}, {'D', 500}, {'C', 100},
                    {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
char *intToRoman(int num) {
    char *str;
    int  i, j, index, cnt;
    str = (char *)malloc(20);
    
    index = 0;
    for (i = 0; i < 7; i = i + 2) {
        cnt = num / rm[i].val;
        num -= cnt * rm[i].val;
        if (cnt == 9) {
            str[index++] = rm[i].c;
            str[index++] = rm[i-2].c;
            continue;
        } else if (cnt == 4) {
            str[index++] = rm[i].c;
            str[index++] = rm[i-1].c;
            continue;
        }
        
        if (cnt >= 5) {
            str[index++] = rm[i-1].c;
            cnt -= 5;
        }
            for (j = 0; j < cnt; j++)
                str[index++] = rm[i].c;
    }
    str[index] = 0;
    return str;
}
