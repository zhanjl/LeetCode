
vector<int> findSubstring(string s, vector<string> &words)
{
    //建立hash表
    unordered_map<string, int>   word_hash; 
     for (vector<string>::iterator it = words.begin(); it != words.end(); it++) {
        word_hash[*it]++;
    }

    vector<int> res;
    int strlen, strnum;
    strnum = words.size();
    strlen = words[0].size();
    if (s.size() < strnum * strlen)
        return res;
     
     for (int i = 0; i <= s.size() - (strnum*strlen); i++) {
        unordered_map<string, int> temp_hash = word_hash;
        bool flag = true;
         for (int j = 0; j < strnum; j++) {
            string substr(s, i + j*strlen, strlen);
             if (temp_hash.find(substr) == temp_hash.end()) {
                flag = false;
                break;
            }
            temp_hash[substr]--; 
        }

        if (flag == false)
            continue;

        unordered_map<string, int>::iterator it = temp_hash.begin();
         while (it != temp_hash.end()) {
            if (it->second != 0)
                break;
            it++;
        }

        if (it == temp_hash.end())
            res.push_back(i);
    }
    return res;
}

