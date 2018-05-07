class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        unordered_map<string, int> hash;
        if (s.size() < 10) return res;
        for (int i = 0; i <= s.size() - 10; ++ i) {
            string str = s.substr(i, 10);
            hash[str] ++;
        }
        for (unordered_map<string, int>::iterator it = hash.begin(); it != hash.end(); it ++) {
            if (it->second >= 2) res.push_back(it->first);
        }
        return res;
    }
};
