class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        unordered_map<string, int> dict;
        if (words.empty()) return res;
        int len = words[0].size();
        for (int i = 0; i < words.size(); ++ i) {
            if (words[i].size() != len) return res;
            dict[words[i]] ++;
        }
        if (s.size() < words.size() * len) return res;
        
        for (int i = 0; i <= s.size() - len; ++ i) {
            string str = s.substr(i, len);
            if (dict.find(str) == dict.end()) continue;
            else {
                unordered_map<string, int> hash = dict;
                int size = words.size();
                for (int j = 0; j < words.size(); ++ j) {
                    string ss = s.substr(i + j * len, len);
                    if (dict.find(ss) == dict.end()) {
                        break;
                    }
                    hash[ss] --;
                    size --;
                    if (hash[ss] < 0) break;
                    if (size == 0) {
                        res.push_back(i);
                    }
                }
            }
        }
        return res;
    }
};