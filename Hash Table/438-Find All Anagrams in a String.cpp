class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char, int> hash;
        if (s.size() < p.size()) return res;
        if (s.size() == p.size()) {
            if (s == p) res.push_back(0);
            return res;
        }
        
        for (int i = 0; i < p.size(); ++ i) {
            hash[p[i]] ++;
        }
        int size = (int)s.size() - (int)p.size() + 1;
        for (int i = 0; i < size; ++ i) {
            unordered_map<char, int> chash = hash;
            int flag = 1, m = i + p.size();
            for (int j = i; j < m; ++ j) {
                if (chash.find(s[j]) == chash.end()) {
                    i = j;
                    flag = 0;
                    break;
                }
                if (-- chash[s[j]] < 0) {
                    while (s[i] != s[j])
                        i ++;
                    flag = 0;
                }
            }
            if (flag == 1) {
                res.push_back(i);
                while (s[i] == s[i + p.size()] && i < size) {
                    res.push_back(++ i);
                }
                if (chash.find(s[i + p.size()]) == chash.end()) {
                    i += p.size();
                }
                else {
                    char ch = s[i + p.size()];
                    while (s[i] != ch) {
                        i ++;
                    }
                }
            }
        }
        return res;
    }
};