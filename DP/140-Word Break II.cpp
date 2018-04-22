class Solution {
public:
    unordered_map<string, int> dict;
    unordered_map<string, vector<string>> cache;
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        if (s.empty()) return res;
        for (int i = 0; i < wordDict.size(); ++ i) {
            dict[wordDict[i]] = 1;
        }
        return wordBreak(s);
    }
    
    vector<string> wordBreak(string s) {
        vector<string> res;
        if (s.empty()) return res;
        int size = s.size();
        for (int i = 0; i < size; ++ i) {
            string left = s.substr(0, i);
            string right = s.substr(i, size - i);
            if (dict.find(right) != dict.end()) {
                vector<string> v;
                if (cache.find(left) != cache.end()) {
                    v = cache[left];
                }
                else {
                    v = wordBreak(left);
                    cache[left] = v;
                }
                for (int j = 0; j < v.size(); ++ j) {
                    v[j] += " " + right;
                    res.push_back(v[j]);
                }
                if (v.empty() && left == "") {
                    res.push_back(right);
                }
            }
        }
        return res;
    }
};