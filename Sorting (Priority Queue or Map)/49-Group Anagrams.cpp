class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> hash;
        vector<vector<string>> res;
        int index = 0;
        for (int i = 0; i < strs.size(); ++ i) {
            priority_queue<char> q;
            for (int j = 0; j < strs[i].size(); ++ j) {
                q.push(strs[i][j]);
            }
            string s = "";
            while (!q.empty()) {
                s += q.top();
                q.pop();
            }
            if (hash.find(s) == hash.end()) {
                vector<string> v;
                v.push_back(strs[i]);
                res.push_back(v);
                hash[s] = index;
                index ++;
            }
            else {
                res[hash[s]].push_back(strs[i]);
            }
        }
        
        return res;
    }
};
