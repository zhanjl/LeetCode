//使用递归
bool partMatch(string s, int sbeg, string p, int pbeg)
{
    if ((sbeg == s.size()) && (pbeg == p.size())) {     //s和p同时结束
        return true;
    }

    if ((sbeg < s.size()) && (pbeg == p.size())) {      //p结束s不结束
        return false;
    }

    if (sbeg == s.size()) {                             //s结束p不结束
        if (p[pbeg + 1] != '*')
            return false;
        return partMatch(s, sbeg, p, pbeg + 2);
    }
                                                        //s和p都不结束 
    if ((pbeg + 1) < p.size() && p[pbeg+1] == '*') {
        //此时有两种选择，p[beg]可以匹配s[sbeg]或者p[beg]匹配空 
        
        //p[beg]匹配空的情况
        if (partMatch(s, sbeg, p, pbeg + 2))
            return true;

        //p[beg]匹配s[sbeg]的情况
        if ((s[sbeg] != p[pbeg]) && (p[pbeg] != '.'))
            return false;

        return partMatch(s, sbeg + 1, p, pbeg);
    } else {
        if (s[sbeg] != p[pbeg] && p[pbeg] != '.')
            return false;
        return partMatch(s, sbeg+1, p, pbeg+1);
    }
}

bool isMatch(string s, string p)
{
    return partMatch(s, 0, p, 0); 
}
