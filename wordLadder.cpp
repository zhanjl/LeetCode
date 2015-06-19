
int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict)
{
    if (beginWord.empty() || endWord.empty() || wordDict.empty())
        return 0;
    queue<pair<string, int> > q;
    unordered_set<string> newDict = wordDict; 
    int cnt = 1;
    newDict.erase(beginWord);
    for (int i = 0; i < beginWord.size(); i++) {
        string str = beginWord;
        for (int j = 0; j < 26; j++) {
            str[i] = 'a' + j;
            if (newDict.count(str) != 0) {
                if (str == endWord) {
                    return cnt + 1;
                }
                q.push(make_pair(str, cnt + 1));
                newDict.erase(str);
            }
        }
    }

    while (!q.empty()) {
        pair<string, int> tmp;
        tmp = q.front();
        q.pop();
        
        string s = tmp.first;  
        cnt = tmp.second;

        for (int i = 0; i < s.size(); i++) {
            string str = s;
            for (int j = 0; j < 26; j++) {
                str[i] = 'a' + j;
                if (newDict.count(str) != 0) {
                    if (str == endWord) {
                        return cnt + 1;
                    }
                    q.push(make_pair(str, cnt + 1));
                    newDict.erase(str);
                }
            }
        }
    }
    return 0;
}

