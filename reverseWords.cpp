
//去除字符串头尾的空格
void noSpace(string &s)
{
    string::iterator first, second;
    first = s.begin();
    while (first < s.end() && *first == ' ') {
        first++;
    }
    second = s.end() - 1;
    while (second >= s.begin() && *second == ' ') {
        second--;
    }
    second++;
    if (first > second)
        second = s.end();
    s = string(first, second);
    return;
}
//两个单词之间只保留一个空格
void oneSpace(string &s)
{
    string::iterator it;
    bool isSpace;

    it = s.begin();
    isSpace = false;
    while (it != s.end()) {
        if (*it == ' ') {
            if (isSpace) {
                it = s.erase(it);
            } else {
                isSpace = true;
                it++;
            }
        } else {
            isSpace = false;
            it++;
        }
    }
    return;
}

void reverseWords1(string &s)
{
    if (s.empty())
        return;
    string::iterator first, second;
    //去除头尾的空格
    noSpace(s); 
    //两个单词之间只保留一个空格
    oneSpace(s);
    reverse(s.begin(), s.end());
    first = second = s.begin();
    for (int i = 0; i < s.size(); i++) {
        if (*second == ' ') {
            reverse(first, second);
            first = second + 1;
        }
        second++;
    }
    reverse(first, second);
    return;
}

void reverseWords2(string &s)
{
    stack<string> words;
    string::iterator first, second, cur;
    bool hasWord;

    hasWord = false;
    first = s.begin();
    for (cur = s.begin(); cur != s.end(); cur++) {
        if (*cur == ' ') {
            if (hasWord) {
                second = cur;
                words.push(string(first, second));
                hasWord = false;    
            }
        } else {
            if (hasWord) {
                second = cur;
            } else {
                second = first = cur;
                hasWord = true;
            }
        }
    }
    if (hasWord) {
        second = cur;
        words.push(string(first, second));
    }
    string str;

    if (!words.empty()) {
        str += words.top();
        words.pop();
    }

    while (!words.empty()) {
        str = str + " " + words.top();
        words.pop(); 
    }
    s = str;
}
