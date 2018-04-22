class Solution {
public:
    unordered_map<string, int> dict;
    unordered_map<string, bool> cache;
    
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty()) return true;
        for (int i = 0; i < wordDict.size(); ++ i) {
            dict[wordDict[i]] = 1;
        }
        return wordBreak(s);
    }
    
    bool wordBreak(string s) {
        if (s.empty()) return true;
        int size = s.size();
        for (int i = 0; i < size; ++ i) {
            string left = s.substr(0, i);
            string right = s.substr(i, size - i);
            if (dict.find(right) != dict.end()) {
                bool res;
                if (cache.find(left) != cache.end()) res = cache[left];
                else {
                    res = wordBreak(left);
                    cache[left] = res;
                }
                if (res) return true;
            }
        }
        return false;
    }
};